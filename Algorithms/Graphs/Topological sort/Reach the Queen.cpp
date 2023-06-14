#include <bits/stdc++.h>
using namespace std; 

long long dfs(int v, vector<int> adj[], long long dp[])
{
    if(dp[v]) 
        return dp[v];
    for(int u : adj[v]) 
        (dp[v] += dfs(u, adj, dp)) %= 1000000007;
    return dp[v];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    long long dp[n + 1] = {};
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    dp[1] = 1;
    dfs(n, adj, dp);
    cout << dp[n];
    return 0;
}
