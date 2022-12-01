#include <bits/stdc++.h>
using namespace std;
int arr[100050];
 
struct node
{
    vector<long long>v;
}st[4000000];
 
void build(long long idx, long long a, long long b)
{
    if(a == b)
    {
        st[idx].v.push_back(arr[a]);
        return;
    }
    int m = (a + b) >> 1;
    build(2 * idx, a, m);
    build(2 * idx + 1, m + 1, b);
    int sz1 = st[2 * idx].v.size(), sz2 = st[2 * idx + 1].v.size(), i = 0, j = 0;
    while(i < sz1 && j < sz2)
    {
        if(st[2 * idx].v[i] <= st[2 * idx + 1].v[j])
        {
            st[idx].v.push_back(st[2 * idx].v[i]);
            i++;
        }
        else
        {
            st[idx].v.push_back(st[2 * idx + 1].v[j]);
            j++;
        }
    }
    while(i < sz1)
    {
       st[idx].v.push_back(st[2 * idx].v[i]);
            i++;
    }
    while(j < sz2)
    {
        st[idx].v.push_back(st[2 * idx + 1].v[j]);
        j++;
    }
}
 
long long solve(long long cnt, long long idx, long long val)
{
    if(st[idx].v.size() == 1)
        return st[idx].v[0];
    long long lcnt = (st[2 * idx].v.end() - lower_bound(st[2 * idx].v.begin(), st[2 * idx].v.end(), val)), rcnt = (st[2 * idx + 1].v.end() - lower_bound(st[2 * idx + 1].v.begin(), st[2 * idx + 1].v.end(), val));
    if(lcnt + rcnt < cnt)
        return -1;
    if(lcnt < cnt)
        return solve(cnt - lcnt, 2 * idx + 1, val);
    else
        return solve(cnt, 2 * idx, val);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q, l, k, ct = 0, i;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    while(q--)
    {
       ct = 0;
       cin >> l >> k;
       cout << solve(k, 1, l) << endl;
    }
    return 0;
}
