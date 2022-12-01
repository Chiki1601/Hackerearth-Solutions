#include<bits/stdc++.h>
using namespace std;
int val[600005], segval[2400020], segind[24000020], tmp, ind[600005];
 
void build(int low, int high, int pos)
{
    if(low == high)
    {
        segval[pos] = val[low];
        segind[pos] = ind[low];
        return;     
    }
    int mid = (low + high) >> 1;
    build(low, mid, 2 * pos + 1);
    build(mid + 1, high, 2 * pos + 2);
    segval[pos] = max(segval[2 * pos + 1], segval[2 * pos + 2]);
    segind[pos] = segind[2 * pos + 1] + segind[2 * pos + 2];
}
 
int get(int low, int high, int ind, int pos)
{ 
    if(low == high)
        return low;
    int num = segind[2 * pos + 1], mid = (low + high) >> 1;
    if(num >= ind)
        return get(low, mid, ind, 2 * pos + 1);
    else
        return get(mid + 1, high, ind - num, 2 * pos + 2);    
}
 
void updind(int low, int high, int pos, int ind, int k, int v)
{
    if(low == high)
    {
        tmp = segval[pos];
        segind[pos] = k;
        segval[pos] = v;
        return;
    }
    int mid = (low + high) >> 1;
    if(ind <= mid)
        updind(low, mid, 2 * pos + 1, ind, k, v);
    else
        updind(mid + 1, high, 2 * pos + 2, ind, k, v);
    segval[pos] = max(segval[2 * pos + 1], segval[2 * pos + 2]);
    segind[pos] = segind[2 * pos + 1] + segind[2 * pos + 2];
}
 
int query(int low, int high, int qlow, int qhigh, int pos)
{
    if(high < qlow || qhigh < low)
        return 0;
    else if(qlow <= low && high <= qhigh)
        return segval[pos];
    int mid = (low + high) >> 1;
    return max(query(low, mid, qlow, qhigh, 2 * pos + 1), query(mid + 1, high, qlow, qhigh, 2 * pos + 2));
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q, i, st, en;
    cin >> n >> q;
    for(i = 0; i < n; i++)
    {
        cin >> val[q + i];
        ind[q + i] = 1;
    }
    int sz = q + n + q, type, l, r, p, k;
    build(0, sz - 1, 0);
    st = q;
    en = q + n - 1;
    for(i = 0; i < q; i++)
    {
        cin >> type;
        if(type & 1)
        {
            cin >> l >> r;
            l = get(0, sz - 1, l, 0);
            r = get(0, sz - 1, r, 0);
            cout << query(0, sz - 1, l, r, 0) << endl;     
        }
        else
        {
            cin >> p >> k; 
            k = get(0, sz - 1, k, 0);
            updind(0, sz - 1, 0, k, 0, 0);
            if(!(p & 1))
            {
                st--;
                updind(0, sz - 1, 0, st, 1, tmp);
            }
            else
            {
                en++;
                updind(0, sz - 1, 0, en, 1, tmp);
            }
        }
    }
    return 0;    
}
