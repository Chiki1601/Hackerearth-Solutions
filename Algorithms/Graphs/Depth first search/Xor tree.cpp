#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int par[100001][20], depth[100001];
long long int xors[100001];
 
void dfs1(int n, int p, int d)
{
	par[n][0] = p;
	depth[n] = d;
	for(int i = 1; i < 20; i++)
		par[n][i]  = par[par[n][i - 1]][i - 1];	
	for(int i = 0; i < graph[n].size(); i++)
    {
		int nxt = graph[n][i];
		if(nxt == p) 
            continue;
		dfs1(nxt, n, d + 1);
	}
}
 
int dfs2(int n, int p)
{
	int x = xors[n];
	for(int i = 0; i < graph[n].size(); i++)
	{
		int nxt = graph[n][i];
		if(nxt != p) 
            x ^= dfs2(nxt, n);
	}
	xors[n] = x;
	return x;
}
 
int lca(int u, int v)
{
	if(depth[u] > depth[v]) 
        swap(u, v);
	int du = depth[u], dv = depth[v];
	int d = depth[v] - depth[u];
	for(int i = 19; i >= 0; i--)
	{
		if(d >= (1<<i))
        {
			v = par[v][i];
			d -= (1<<i);
		}
	}
	if(u == v) 
        return u;
	for(int i = 19; i >= 0; i--)
    {
		if(par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
 
void solve()
{
	int n, qry;
	cin >> n >> qry;
	vector<vector<int>> q;
	for(int i = 0; i <= n; i++)
	{
		graph[i].clear();
		xors[i] = 0;
		depth[i] = 0;
		for(int j = 0; j < 20; j++) 
            par[i][j] = 0;
	}
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 0; i < qry; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vector<int> vec{u, v, w};
		q.push_back(vec);
	}
	dfs1(1, 0, 1);
	for(int i = 0; i < qry; i++)
	{
		int u = q[i][0], v = q[i][1], w = q[i][2];
		int p = lca(u, v);
		xors[p] ^= w;
		xors[par[p][0]] ^= w;
		xors[u] ^= w;
		xors[v] ^= w;
	}
	dfs2(1, 0);
	long long ans = 0;
	for(int i = 1; i <= n; i++) 
        ans += (long long) xors[i];
	cout << ans << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
        solve();
}
