#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[1005];
int control[1005], dp[1005][2005];
 
int dijkstra(int source, int n)
{
    memset(dp, -1, sizeof(dp));
    set<pair<int,pair<int, int>>> s;
    int index = (control[source] == 0) ? (1000) : (1002), ans = INT_MAX; 
    dp[source][index] = 0;
    s.insert(make_pair(0, make_pair(source, index))); 
    while(!s.empty())
	{
        int u = s.begin()->second.first, dif = s.begin()->second.second;
        s.erase(s.begin());
        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].first, w = g[u][i].second;
            int ind = (control[v] == 0) ? (dif - 1) : (dif + 1);
            if(dp[v][ind] == -1 || dp[v][ind] > dp[u][dif] + w)
            {
                s.erase(make_pair(dp[v][ind], make_pair(v, ind)));
                dp[v][ind] = dp[u][dif] + w;
                s.insert(make_pair(dp[v][ind], make_pair(v, ind)));
            }
        }
    }
    for(int i = -1; i <= 1; i++)
	{
        if(dp[n][1001 + i] != -1)
            ans = min(ans, dp[n][1001 + i]);
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
	{
        int u, v, l;
        cin >> u >> v >> l;
        g[u].push_back(make_pair(v, l));
    }
    for(int i = 1; i <= n; i++)
        cin >> control[i];
    int ans = dijkstra(1, n);
    if(ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
}
