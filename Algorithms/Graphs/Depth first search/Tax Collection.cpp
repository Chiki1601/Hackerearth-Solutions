#include <bits/stdc++.h>
using namespace std;
vector<int> dp(100001, 0), adj[100001], a(100001), pr(1000001, 0);

void dfs(int u, int p)
{
    dp[u] = pr[a[u]];
    for(int v : adj[u])
    {
        if(v != p)
        {
            dfs(v, u);
            dp[u] += dp[v];
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, i, u, v, j, i_2;
    cin >> t;
    for(i = 2; i <= 1000000; i += 2) 
        pr[i]++;
    for(i = 3; i <= 1000000; i += 3) 
        pr[i]++;
    for(i = 5; i <= 1000000; i += 6) 
    {
        if(!pr[i]) 
            for(j = i; j <= 1000000; j += i) 
                pr[j]++;
        i_2 = i + 2;
        if(!pr[i_2]) 
            for(j = i_2; j <= 1000000; j += i_2) 
                pr[j]++;
    }
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            adj[i].clear();
        }
        for(i = 1; i < n; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        for(i = 1; i < n; i++)
            cout << dp[i] << ' ';
        cout << dp[n] << "\n";
    }
    return 0;
}
