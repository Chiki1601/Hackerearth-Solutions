#include <bits/stdc++.h>
using namespace std;
int par[100001];
 
int findSet(int u) 
{
	return par[u] = par[u] == u ? u : findSet(par[u]);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long ans[100001];
	int n, q, affected[300001], sz[100001];
	vector<pair<int, int>> edges[100001];
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) 
	{
		par[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i < n; ++i) 
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[w].push_back({u, v});
	}
	for (int d = 1; d <= 100000; ++d) 
	{
		int pool = 0;
		for(int w = d; w <= 100000; w += d) 
		{
			for(auto x : edges[w]) 
			{
				int u = x.first, v = x.second;
				int pu = findSet(u), pv = findSet(v);
				affected[pool++] = u;
				affected[pool++] = v;
				ans[d] += (long long)sz[pu] * sz[pv];
				par[pu] = pv;
				sz[pv] += sz[pu];
			}
		}
		for(int i = 0; i < pool; ++i) 
		{
			par[affected[i]] = affected[i];
			sz[affected[i]] = 1;
		}
		pool = 0;
	}
	while(q--) 
	{
		int d;
		cin >> d;
		cout << ans[d] << "\n";
	}
}
