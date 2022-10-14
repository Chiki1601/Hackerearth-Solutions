#include <bits/stdc++.h>
using namespace std;
int tc, n, m, assign[1005];
bool vis[1005];
vector<int> adj[1005];
 
bool matching(int u) 
{
    for(auto v : adj[u]) 
    {
        if(vis[v]) 
            continue;
        vis[v] = 1;
        if(assign[v] == 0 || matching(assign[v])) 
        {
            assign[v] = u;
            return true;
        }
    }
    return false;
}
  
int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) 
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) 
        {
            adj[i].clear();
            assign[i] = 0;
        }
        for(int i = 1; i <= m; i++) 
        {
            int u, v;
            cin >> u >> v;
            adj[v].emplace_back(u);
        }
        int ans = -1;
        for(int i = 1; i <= n; i++) 
        {
            for(int j = 1; j <= n; j++)
                vis[j] = 0;
            if(!matching(i))
                ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
