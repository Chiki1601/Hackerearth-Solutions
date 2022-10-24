#include <bits/stdc++.h>
int n, dfn[100009], tot, end[100009], anc[100009][20], tag[400009], sum[400009];
std::vector<int> ne[100009];
 
struct tri 
{
	int a, b;
	bool f;
	tri() {}
	tri(int _a, int _b, bool _f) : a(_a), b(_b), f(_f) {}
};std::vector<tri> evt[100009];
 
void dfs(int x, int fa) 
{
	dfn[x] = ++tot;
	anc[x][0] = fa;
	for(int i = 1; i < 20; ++i)
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for(auto y : ne[x])
		if(y != fa)
			dfs(y, x);
	end[x] = tot;
}
 
bool isanc(int u, int v) 
{
	return dfn[u] <= dfn[v] && end[v] <= end[u];
}
 
int up(int u, int v) 
{
	for(int i = 19; i >= 0; --i)
		if(isanc(u, anc[v][i]) && u != anc[v][i])
			v = anc[v][i];
	return v;
}
 
void addrec(int x1, int x2, int y1, int y2) 
{
	if(1 <= x1 && x1 <= x2 && x2 <= n && 1 <= y1 && y1 <= y2 && y2 <= n) 
	{
		evt[x1].push_back(tri(y1, y2, true));
		evt[x2 + 1].push_back(tri(y1, y2, false));
	}
}
 
void add(int u, int v) 
{
	if(dfn[u] > dfn[v]) 
		std::swap(u, v);
	if(isanc(u, v)) 
	{
		int r = up(u, v);
		addrec(1, dfn[r] - 1, dfn[v], end[v]);
		addrec(dfn[v], end[v], end[r] + 1, n);
	}
	else 
		addrec(dfn[u], end[u], dfn[v], end[v]);
}
 
int get(int x, int l, int r) 
{
	if(tag[x]) 
		return r - l + 1;
	else 
		return sum[x];
}
 
void mdf(int x, int l, int r, int ql, int qr, bool f) 
{
	if(ql <= l && r <= qr) 
	{
		if(f) 
			tag[x]++;
		else 
			tag[x]--;
		return ;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) 
		mdf(x << 1, l, mid, ql, qr, f);
	if(qr > mid) 
		mdf(x << 1 | 1, mid + 1, r, ql, qr, f);
	sum[x] = get(x << 1, l, mid) + get(x << 1 | 1, mid + 1, r);
}
 
int qsum(int x, int l, int r, int ql, int qr) 
{
	if(tag[x]) 
		return std::min(qr, r) - std::max(ql, l) + 1;
	if(ql <= l && r <= qr) 
		return get(x, ql, qr);
	int mid = (l + r) >> 1, ret = 0;
	if(ql <= mid) 
		ret += qsum(x << 1, l, mid, ql, qr);
	if(qr > mid) 
		ret += qsum(x << 1 | 1, mid + 1, r, ql, qr);
	return ret;
}
 
int main() 
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n;
	for(int i = 1; i < n; ++i) 
	{
		int u, v;
		std::cin >> u >> v;
		ne[u].push_back(v), ne[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i)
		for(int j = i + i; j <= n; j += i)
			add(i, j);
	long long ans = (long long)n * (n - 1) / 2;
	for(int i = 1; i < n; ++i) 
	{
		for(auto x : evt[i])
			mdf(1, 1, n, x.a, x.b, x.f);
		ans -= qsum(1, 1, n, i + 1, n);
	}
	std::cout << ans << std::endl;
    return 0;
}
