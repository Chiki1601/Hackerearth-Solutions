#include <bits/stdc++.h>
using namespace std;
long long n, q, a[100009];
 
struct node 
{
    long long sum, d, s;
};node t[400036];
 
long long calcSum(long long s, long long len, long long d) 
{
    return (1000000007 + len * (2 * s + (len - 1) * d) / 2) % 1000000007;
}
 
void down(long long i, long long l, long long r) 
{
    if(t[i].s) 
    {
        long long s = t[i].s, d = t[i].d, m = (l + r) >> 1;
        long long sLeft = s, sRight = s + (m - l + 1) * d;
        t[i<<1].s = (t[i<<1].s + sLeft) % 1000000007, t[i<<1].d = (t[i<<1].d + d) % 1000000007;
        t[i<<1|1].s = (t[i<<1|1].s + sRight) % 1000000007, t[i<<1|1].d = (t[i<<1|1].d + d) % 1000000007;
        t[i<<1].sum = (t[i<<1].sum + calcSum(sLeft, m - l + 1, d) + 1000000007) % 1000000007;
        t[i<<1|1].sum = (t[i<<1|1].sum + calcSum(sRight, r - m, d) + 1000000007) % 1000000007;
        t[i].s = t[i].d = 0;
    }
}
 
void build(long long i = 1, long long l = 1, long long r = n) 
{
    if(l > r) 
        return;
    if(l == r) 
    {
        t[i].sum = a[l];
        return;
    }
    long long m = (l + r) >> 1;
    build(i << 1, l, m), build(i << 1 | 1, m + 1, r);
    t[i].sum = (t[i<<1].sum + t[i<<1|1].sum + 1000000007) % 1000000007;
}
 
void update(long long u, long long v, long long s, long long d, long long i = 1, long long l = 1, long long r = n) 
{
    if(u > r || v < l) 
        return;
    if(u <= l && r <= v) 
    {
        long long x = s + (l - u) * d, len = r - l + 1;
        t[i].s = (t[i].s + x) % 1000000007;
        t[i].d = (t[i].d + d) % 1000000007;
        t[i].sum = (t[i].sum + calcSum(x, len, d) + 1000000007) % 1000000007;
        return;
    }
    down(i, l, r);
    long long m = (l + r) >> 1;
    update(u, v, s, d, i<<1, l, m), update(u, v, s, d, i << 1 | 1, m + 1, r);
     t[i].sum = (t[i<<1].sum + t[i<<1|1].sum + 1000000007) % 1000000007;
}
 
long long get(long long u, long long v, long long i = 1, long long l = 1, long long r = n) 
{
    if(u > r || v < l) 
        return 0;
    if(u <= l && r <= v) 
        return t[i].sum % 1000000007;
    down(i, l, r);
    long long m = (l + r) >> 1;
    return (1000000007 + get(u, v, i<<1, l, m) + get(u, v, i << 1 | 1, m + 1, r)) % 1000000007;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    build();
    for(int i = 1; i <= q; i++) 
    {
        long long type, l, r;
        cin >> type >> l >> r;
        if(type == 1) 
        {
            long long des = min(l + r - 1, n), d = -1;
            long long s = r;
            update(l, des, s, d);
            r -= (des - l + 1);
            long long len = (r / n);
            d = -len, s = calcSum(r, len, -n);
            update(1, n, s, d);
            r %= n;
            d = -1, s = r;
            update(1, 1 + r - 1, s, d);
        } 
        else 
        {
            if(l <= r) 
                cout << get(l, r) % 1000000007 << endl;
            else 
                cout <<  (t[1].sum - get(r+1, l-1) + 1000000007) % 1000000007 << endl;
        }
    }
    return 0;
}
