#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long> A, maxSeg, minSeg, mul, add;
 
void build(int v, int tl, int tr) 
{
    if(tl == tr) 
    {
        maxSeg[v] = A[tl];
        minSeg[v] = A[tl];
    } 
    else 
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        maxSeg[v] = max(maxSeg[v * 2], maxSeg[v * 2 + 1]);
        minSeg[v] = min(minSeg[v * 2], minSeg[v * 2 + 1]);
    }
}
 
void push(int v) 
{
    maxSeg[v * 2] *= mul[v];
    maxSeg[v * 2 + 1] *= mul[v];
    minSeg[v * 2] *= mul[v];
    minSeg[v * 2 + 1] *= mul[v];
    maxSeg[v * 2] += add[v];
    maxSeg[v * 2 + 1] += add[v];
    minSeg[v * 2] += add[v];
    minSeg[v * 2 + 1] += add[v];
    mul[v * 2] *= mul[v];
    add[v * 2] *= mul[v];
    mul[v * 2 + 1] *= mul[v];
    add[v * 2 + 1] *= mul[v];
    add[v * 2] += add[v];
    add[v * 2 + 1] += add[v];
    add[v] = 0;
    mul[v] = 1;
}
 
int firstOccur(long long x, int v, int tl, int tr) 
{
    if(x > maxSeg[v] || x < minSeg[v]) 
        return -1;
    if(tl == tr) 
        return tl;
    int tm = (tl + tr) / 2;
    push(v);
    int ret = firstOccur(x, v * 2, tl, tm);
    if(ret == -1) 
        ret = firstOccur(x, v * 2 + 1, tm + 1, tr);
    return ret;
}
 
int lastOccur(long long x, int v, int tl, int tr) 
{
    if(x > maxSeg[v] || x < minSeg[v]) 
        return -2;
    if(tl == tr) 
        return tl;
    int tm = (tl + tr) / 2;
    push(v);
    int ret = lastOccur(x, v * 2 + 1, tm + 1, tr);
    if(ret == -2) 
        ret = lastOccur(x, v * 2, tl, tm);
    return ret;
}
 
void update(long long cadd, long long cmul, int v, int l, int r, int tl, int tr) 
{
    if(l > r) 
        return;
    if(l == tl && tr == r) 
    {
        maxSeg[v] *= cmul;
        maxSeg[v] += cadd;
        minSeg[v] *= cmul;
        minSeg[v] += cadd;
        mul[v] *= cmul;
        add[v] *= cmul;
        add[v] += cadd;
    } 
    else 
    {
        push(v);
        int tm = (tl + tr) / 2;
        update(cadd, cmul, v * 2, l, min(r, tm), tl, tm);
        update(cadd, cmul, v * 2 + 1, max(l, tm + 1), r, tm + 1, tr);
        maxSeg[v] = max(maxSeg[2 * v], maxSeg[2 * v + 1]);
        minSeg[v] = min(minSeg[v<<1], minSeg[v<<1|1]);
    }
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    A.resize(n);
    for(int i = 0; i < n; i++) 
        cin >> A[i];
    mul.assign(4 * n, 1);
    add.assign(4 * n, 0);
    maxSeg.resize(4 * n);
    minSeg.resize(4 * n);
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--) 
    {
        int type;
        cin >> type;
        if(type == 3) 
        {
            long long x;
            cin >> x;
            cout << lastOccur(x, 1, 0, n - 1) - firstOccur(x, 1, 0, n - 1) + 1 << "\n";
        } 
        else 
        {
            long long l, r, x;
            cin >> l >> r >> x;
            l--; 
            r--;
            if(type == 1) 
                update(x, 1, 1, l, r, 0, n - 1);
            else 
                update(0, x, 1, l, r, 0, n - 1);
        }
    }
    return 0;
}
