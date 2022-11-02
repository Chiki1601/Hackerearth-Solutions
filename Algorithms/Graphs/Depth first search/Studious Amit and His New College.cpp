#include <bits/stdc++.h>
using namespace std;
vector <int> adj[100001];
int visited[100001], n, m;
 
bool dfs(int node) 
{
	if(visited[node] == 2)
		return false;
	if(visited[node] == 1)
		return true;
	visited[node] = 1;
	for(auto child : adj[node]) 
	{
		if(dfs(child))
			return true;
	}
	visited[node] = 2;
	return false;
}
 
bool solve() 
{
	for(int i = 0; i < n; ++i) 
		if(!visited[i] && dfs(i)) 
			return false;
	return true;
}
 
int32_t main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;    
	cin >> t;
    while(t--) 
	{
    	for(int i = 0; i < 100001; ++i)
    		adj[i].clear();
    	cin >> n >> m;
    	while(m--) 
		{
    		int a, b;
    		cin >> a >> b;
    		a--, b--;
    		adj[a].push_back(b);
    	}
		memset(visited, 0, sizeof(visited));
		cout << solve() << endl;
    }
    return 0;
}
