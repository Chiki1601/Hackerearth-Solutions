#include<bits/stdc++.h>
using namespace std;
 
void dfs(long long v, vector<bool>& vis, vector<long long> adj[], long long& sz)
{
	sz++;
	vis[v] = true;
	for(long long u : adj[v])
	{
		if(!vis[u])
			dfs(u, vis, adj, sz);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t;
	cin >> t;
	while(t--)
	{
		long long n, m, a, b, ans = 0;
		cin >> n >> m;
		vector<long long> adj[n + 1];
		vector<bool> vis(n + 1,false);
		while(m--)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(long long i = 1; i <= n; i++)
		{
			long long sz = 0;
			if(!vis[i])
			{
				dfs(i, vis, adj, sz);
				ans += (sz * (n - sz));
			}
		}
		cout << ans << endl;
	}
}
