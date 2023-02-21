#include <bits/stdc++.h>
using namespace std;
vector<int> dp(200001);

void dfs(int node, int par, vector<vector<pair<int ,int>>>&adj)
{
	for(auto child : adj[node])
	{
		int w = child.second, childNode = child.first;
		if(childNode == par)
			continue;
		dp[childNode] = w + dp[node];
		dfs(childNode, node, adj);
	}
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, tot = 0, best = 0, diam = 0;
    cin >> n;
	vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < n - 1; ++i) 
	{
       	int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		tot += c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dfs(0, -1, adj);
    for(int i = 1; i < n; ++i) 
	{
        if(dp[best] < dp[i]) 
            best = i;
    }
    fill(dp.begin(), dp.end(), 0);
    dfs(best, -1, adj);
    for(int i = 0; i < n; ++i) 
        diam = max(diam, dp[i]);
    cout << 2 * tot - diam << "\n";
}
