#include <bits/stdc++.h>
using namespace std; 
 
void dfs(int v, int p, vector<int> adj[], vector<bool> &vis)
{
    for(auto u : adj[v])
    {
        if(u == p)
			continue;
        dfs(u, v, adj, vis);
        if(!vis[u])
			vis[v] = true;
    }
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t = 1, n, p;
    cin >> t; 
    while(t--)
    {
        cin >> n;
        vector<int> adj[n + 1]; 
        vector<bool> vis(n + 1, false);
        for(int i = 1; i < n; i++)
        {
            cin >> p;
            adj[p].push_back(i + 1);
        }
        dfs(1, -1, adj, vis);
        if(vis[1])
			cout << "A" << endl;
        else 
			cout << "B" << endl;
    }
    return 0;
}
