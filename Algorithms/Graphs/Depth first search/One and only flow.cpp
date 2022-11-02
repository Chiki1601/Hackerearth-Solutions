#include  <bits/stdc++.h>
using namespace std;
int n, m, tot[200005];
bool vis[200005], onstk[200005], ans;
vector<int> g[200005];
 
void dfs(int u) 
{
    vis[u] = onstk[u] = 1;
    for(int v : g[u]) 
    {
        if(vis[v]) 
        {
            if(!onstk[v]) 
                ans = 0;
            else 
            {
                tot[v]--;
                tot[u]++;
            }
        } 
        else 
        {
            dfs(v);
            tot[u] += tot[v];
        }
    }
    if(u != 1 and tot[u] != 1) 
        ans = 0;
    onstk[u] = 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            g[i].clear();
        for(int i = 0; i < m; i++) 
        {
            int u, v;
            cin >> u >> v;
            if(u != v) 
                g[u].emplace_back(v);
        }
        fill(vis, vis + n + 1, 0);
        fill(tot, tot + n + 1, 0);
        ans = 1;
        dfs(1);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            cnt += vis[i];
        if(cnt != n) 
            ans = 0;
        if(ans) 
            puts("Yes");
        else 
            puts("No");
    }
    return 0;
}
