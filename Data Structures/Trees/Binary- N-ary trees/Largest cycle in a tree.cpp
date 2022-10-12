#include <bits/stdc++.h>
using namespace std;
int start = -1, total = 0;
 
void dfs(int u, int len, vector<vector<int>> &adj, bool visited[])
{
	visited[u] = true;
	if(total < len)
	{
 		total = len;
 		start = u;
	}
	for(auto v : adj[u])
	{
 		if(!visited[v])
  			dfs(v, len + 1, adj, visited);
	}
	return;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, u, v;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	bool visited[n + 1];
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < n - 1; ++i)
	{
 		cin >> u >> v;
 		adj[u].push_back(v);
 		adj[v].push_back(u);
	}
	dfs(1, 1, adj, visited);
	cout << start << " ";
	total = 0;
	memset(visited, false, sizeof(visited));
	dfs(start, 1, adj, visited);
	cout << start;
}
