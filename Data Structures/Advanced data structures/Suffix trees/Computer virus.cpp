#include <bits/stdc++.h>
using namespace std;
string s[2005];
char _s[4000100];
int ql[1000100], qr[1000100], qans[1000100], last[4000100], base;
vector<int> queries[2005][2005], ones[2005];
 
struct E 
{
	int pre, suf, mx, len;
	E() : pre(0), suf(0), mx(0), len(0) {}
	E(int x) : pre(x), suf(x), mx(x), len(x) {}
	E(const E &l, const E &r) 
	{
		len = l.len + r.len;
		if(l.len == l.mx)
			pre = l.len + r.pre;
		else
			pre = l.pre;
		if(r.len == r.mx)
			suf = r.len + l.suf;
		else
			suf = r.suf;
		mx = max(max(l.mx, r.mx), l.suf + r.pre);
	}
};
 
namespace T 
{
	E t[1 << 23];
	void clear() 
	{
		for(int i = 0; i < base; ++i) 
		{
			t[i + base] = E();
			t[i + base].len = 1;
		}
		for(int i = base - 1; i > 0; --i)
			t[i] = E(t[i * 2], t[i * 2 + 1]);
	}
	void put(int v) 
	{
		v += base;
		t[v] = E(1);
		while(v > 1) 
		{
			v /= 2;
			t[v] = E(t[v * 2], t[v * 2 + 1]);
		}
	}
	E get(int l, int r, int v = 1, int cl = 0, int cr = base) 
	{
		if(l <= cl && cr <= r)
			return t[v];
		if(r <= cl || cr <= l)
			return E();
		int cc = (cl + cr) / 2;
		return E(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
	}
} 
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, q;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) 
	{
		cin >> _s;
		s[i] = _s;
	}
	base = 1;
	while(base < m)
		base *= 2;
	cin >> q;
	for(int i = 0; i < q; ++i) 
	{
		int xl, yl, xr, yr;
		cin >> xl >> yl >> xr >> yr;
		--xl, --yl;
		queries[xl][xr].push_back(i);
		ql[i] = yl, qr[i] = yr;
	}
	for(int i = 0; i < m; ++i)
		last[i] = n;
	for(int l = n - 1; l >= 0; --l) 
	{
		for(int j = 0; j < m; ++j)
			if(s[l][j] == '1')
				last[j] = l;
		T::clear();
		for(int i = 0; i < n + 1; ++i)
			ones[i].clear();
		for(int j = 0; j < m; ++j)
			ones[last[j]].push_back(j);
		for(int r = l + 1; r <= n; ++r) 
		{
			for(int x : ones[r - 1]) 
				T::put(x);
			for(int id : queries[l][r]) 
			{
				int L = ql[id], R = qr[id];
				auto e = T::get(L, R);
				qans[id] = e.mx * (r - l);
			}
		}
	}
	for(int i = 0; i < q; ++i)
		cout << qans[i] << "\n";
}
