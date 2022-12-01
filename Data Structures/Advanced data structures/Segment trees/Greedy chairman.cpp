#include <bits/stdc++.h>
using namespace std;
long long n, q, a[200009], nNode, f[200009], inv[200009], ver[200009];
 
struct node 
{
    long long l, r, val;
};node t[40000180];
 
long long mult(long long a, long long b)
{
	return (1ll * a * b) % 1000000007;
}
 
long long c(long long x, long long y)
{
	if(y > x || y < 0 || y < 0) 
        return 0;
	long long ans = mult(f[x], inv[y]);
	ans = mult(ans, inv[x - y]);
	return ans;
}
 
long long bp(long long y, long long x)
{
	long long ans = 1;
	while(x)
    {
		if(x & 1) 
            ans = mult(ans, y);
		y = mult(y, y);
		x >>= 1;
	}
	return ans;
}
 
long long update(long long p, long long old, long long l = 1, long long r = n) 
{
    long long i = ++nNode;
    t[i] = t[old];
    if(l == r) 
    {
        t[i] = {0, 0, t[i].val + 1};
        return i;
    }
    long long m = (l + r) >> 1;
    if(p <= m) 
        t[i].l = update(p, t[old].l, l, m);
    else 
        t[i].r = update(p, t[old].r, m + 1, r);
    t[i].val = t[t[i].l].val + t[t[i].r].val;
    return i;
}
 
long long calc(long long u, long long v) 
{
    return t[v].val - t[u].val;
}
 
long long get(long long u, long long v, long long x, long long k, long long cnt = 0, long long l = 1, long long r = n) 
{
    long long val = calc(t[u].l, t[v].l);
    if(l == r) 
        return c(calc(u, v), k - cnt);
    long long m = (l + r) >> 1;
    if(x <= val) 
        return get(t[u].l, t[v].l, x, k, cnt, l, m);
    else 
        return get(t[u].r, t[v].r, x - val, k, cnt + val, m + 1, r);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    vector<long long> b;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 1; i <= n; i++)
    {
        long long j = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        ver[i] = update(j, ver[i - 1]);
    }
    f[0] = inv[0] = 1;
	for(int i = 1; i <= n; i++)
		f[i] = mult(f[i - 1], i);
	inv[n] = bp(f[n], 1000000005);
	for(int i = n - 1; i >= 0; i--)
		inv[i] = mult(inv[i + 1], i + 1);
    for(int i = 1; i <= q; i++) 
    {
        long long l, r, k;
        cin >> l >> r >> k;
        cout << get(ver[l - 1], ver[r], k, k) << endl;
    }
    return 0;
}
