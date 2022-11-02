#include <bits/stdc++.h>
using namespace std;
int n, m, up[200002], tin[200002], timer, d[200002], f[200002], ans, res;
vector <int> g[200002];
vector <pair<int, int>> e[200002];
 
inline int get(int v, int v2, int k) 
{
	int r = 0;
	for(const auto& x : e[v]) 
    {
		if(x.second == v2) 
            continue;
		--k;
		r += x.first;
		if(k <= 0) 
            break;
	}
	return r;
}
 
inline void dfs(int v, int pr = -1) 
{	
	up[v] = 200002;
	tin[v] = ++timer;
	for(const int& v2 : g[v]) 
    {
		if(v2 == pr) 
            continue;
		if(tin[v2]) 
			up[v] = min(up[v], tin[v2]);
		else 
        {
			dfs(v2, v);
			up[v] = min(up[v], up[v2]);
			f[v] = max(f[v], f[v2]);
			e[v].push_back(make_pair(f[v2], v2));
		}
	}
	sort(e[v].begin(), e[v].end());
	reverse(e[v].begin(), e[v].end());
	f[v] += up[v] > tin[v];
	ans += up[v] <= tin[v];
}
 
inline void dfs2(int v, int pr = -1, int upper = 0) 
{	
	res = max(res, max(get(v, -1, 1) + upper, get(v, -1, 2)) + (up[v] > tin[v]));
	for(const auto& x : e[v]) 
    {
		int v2 = x.second;
		if(v2 == pr) 
            continue;
		dfs2(v2, v, max(upper, get(v, v2, 1)) + (up[v] > tin[v]));
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; ++i) 
    {
		int v1, v2;
		cin >> v1 >> v2;
		--v1, --v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(0);
	dfs2(0);
	cout << ans + res << endl;
	return 0;
}
