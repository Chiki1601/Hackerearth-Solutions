#include <bits/stdc++.h>
using namespace std;
 
struct SegTree 
{
    int n;
    vector<int> t;
    SegTree(int n_) 
	{
        n = n_;
        t.resize(2 * n + 5, 0);
    }
    void modify(int p, int value) 
	{
      	for(t[p += n] = value; p > 1; p >>= 1) 
		  	t[p>>1] = max(t[p], t[p^1]);
    }
    int query(int l, int r)
	{ 
      	if(l > r) 
		  	return 0;
      	r++; 
      	int res = 0;
      	for(l += n, r += n; l < r; l >>= 1, r >>= 1) 
		{
        	if(l & 1) 
				res = max(res, t[l++]);
        	if(r & 1) 
				res = max(res, t[--r]);
      	}
      	return res;
    }
};
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
		int n, ans = 0;
		cin >> n;
		vector<int> v(n), val(n + 1);
		for(int i = 0; i < n; i++) 
			cin >> v[i];
		SegTree a(n + 1), b(n + 1), c(n + 1);
		for(int i = 0; i < n; i++) 
		{
			int lis = a.query(1, v[i] - 1), lds = b.query(v[i] + 1, n), eq_l = c.query(1, v[i]), eq_r = c.query(v[i], n), l = val[v[i]];
			ans = max(ans, 1 + max(l, max(max(eq_l, lis), max(eq_r, lds))));
			a.modify(v[i], max(a.query(v[i], v[i]), 1 + max(lis, eq_l)));
			b.modify(v[i], max(b.query(v[i], v[i]), 1 + max(lds, eq_r)));
			c.modify(v[i], 1 + val[v[i]]);
			val[v[i]] = 1 + max(l, max(max(eq_l, lis), max(eq_r, lds)));   
		}
		cout << ans << "\n";
	}
	return 0;  
}
