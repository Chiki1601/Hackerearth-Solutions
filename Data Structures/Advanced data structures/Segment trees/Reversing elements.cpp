#include <bits/stdc++.h>
using namespace std;
int n, q;
 
struct node_t 
{
    long long sum, prf, suf, ans;
    node_t() : ans(-1000000000023111992) {}
    node_t(int val) : sum(val), prf(val), suf(val), ans(val) {}
    friend node_t operator + (const node_t& a, const node_t& b) 
	{
        if(a.ans == -1000000000023111992) 
			return b;
        if(b.ans == -1000000000023111992) 
			return a;
        node_t res;
        res.sum = a.sum + b.sum;
        res.prf = max(a.prf, a.sum + b.prf);
        res.suf = max(b.suf, a.suf + b.sum);
        res.ans = max(a.suf + b.prf, max(a.ans, b.ans));
        return res;
    }
};node_t st[100005 << 2];
 
void upd(int p, int i, int L, int R, int val) 
{
    if(i < L || R < i) 
		return;
    if(L == R) 
	{
        st[p] = node_t(val);
        return;
    }
    upd(p << 1, i, L, L + R >> 1, val);
    upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
    st[p] = st[p << 1] + st[p << 1 | 1];
}
 
node_t query(int p, int l, int r, int L, int R) 
{
    if(r < L || R < l) 
		return node_t();
    if(l <= L && R <= r) 
		return st[p];
    return query(p << 1, l, r, L, L + R >> 1) + query(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    for(int i = 0; i < n; ++i) 
	{
        int x; 
        cin >> x;
        assert(-1e6 <= x && x <= 1000000);
        upd(1, i, 0, n - 1, x);
    }
    while(q--) 
	{
        int l, r; 
        cin >> l >> r; 
        l--; 
        r--;
        assert(0 <= l && l <= r && r < n);
        node_t res = query(1, l, r, 0, n - 1);
        swap(res.prf, res.suf);
        res = query(1, 0, l - 1, 0, n - 1) + res + query(1, r + 1, n - 1, 0, n - 1);
        cout << res.ans << endl;
    }
    return 0;
}
