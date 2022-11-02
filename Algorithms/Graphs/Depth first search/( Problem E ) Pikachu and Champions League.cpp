#include <bits/stdc++.h>
using namespace std;
int n, q, d[500005], dp[500005][20], a[500005];
vector<int> g[500005];
 
void dfs(int u, int p)
{
	dp[u][0] = p;
	for(int i : g[u])
    {
		if(i == p)	
            continue;
		d[i] = 1 + d[u];
		dfs(i, u);
	}
}
 
int lca(int u, int v)
{
	if(d[u] > d[v])
		swap(u, v);
	int k = d[v] - d[u];
	for(int i = 19; i >= 0; i--)
    {
		if(k >= (1 << i))
        {
			v = dp[v][i];
			k -= (1 << i);
		}
	}
	if(u == v)	
        return u;
	for(int i = 19; i >= 0; i--)
    {
		if(dp[u][i] != dp[v][i])
        {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[v][0];
}	
 
int dis(int u, int v)
{
	return d[u] + d[v] - 2 * d[lca(u, v)];
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n - 1; i++)
    {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	d[1] = 0;
	dfs(1, 0);
	for(int j = 1; j < 20; j++)
		for(int i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
	while(q--)
    {
		int x, id = 1, m = 0; 	
        cin >> x;
		for(int i = 1; i <= x; i++)
			cin >> a[i];
		for(int i = 2; i <= x; i++)
        {
			int y = dis(a[i], a[1]);
			if(y > m)
            {
				m = y; 
				id = i;
			}
		}
		m = 0;
		for(int i = 1; i <= x; i++)
			m = max(m, dis(a[i], a[id]));
		cout << m << endl;
	}
	return 0;	
} 
