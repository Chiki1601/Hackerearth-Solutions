#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int>> adj[80010];
int n, len, in[80010], out[80010], ti, par[80010][20];
long long d[80010], dp[80010], dp1[80010], dp2[80010], a[80010];
pair <long long, long long> minval[80010];
 
void dfs(int u, int p) 
{
    in[u] = ++ti;
    par[u][0] = p;
    for(int i = 1; i < 20; ++i)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for(auto [v, w]: adj[u]) 
    {
        if(v == p) 
            continue;
        d[v] = d[u] + w;
        dfs(v, u);
    }
    out[u] = ti;
}
 
int check(int u, int v) 
{
    return in[u] <= in[v] && out[v] <= out[u];
}
 
int LCA(int u, int v) 
{
    if(check(u, v)) 
        return u;
    for(int i = 19; i >= 0; --i)
        if(par[u][i] != -1 && !check(par[u][i], v)) 
            u = par[u][i];
    return par[u][0];
}
 
long long dist(int u, int v) 
{
    return d[u] + d[v] - 2 * d[LCA(u, v)];
}
 
void down(int u, int p)
{
    dp1[u] = a[u];
    minval[u] = {1e18, 1e18};
    for(auto [v, w]: adj[u]) 
    {
        if(v == p) 
            continue;
        down(v, u);
        dp1[u] = min(dp1[u], dp1[v] + w);
        if(dp1[v] + w < minval[u].first) 
            minval[u].second = minval[u].first, minval[u].first = dp1[v] + w;
        else if(dp1[v] + w < minval[u].second) 
            minval[u].second = dp1[v] + w;
    }
}
 
void up(int u, int p) 
{
    dp2[u] = min(a[u], dp2[u]);
    for(auto [v, w]: adj[u]) 
    {
        if(v == p) 
            continue;
        dp2[v] = dp2[u] + w;
        if(dp1[v] + w == minval[u].first) 
            dp2[v] = min(dp2[v], minval[u].second + w);
        else 
            dp2[v] = min(dp2[v], minval[u].first + w);
        up(v, u);
    }
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; ++i) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u; 
        --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    len = 300;
    memset(par, -1, sizeof(par));
    for(int i = 1; i < n; ++i) 
        dp[i] = 1e18;
    dfs(0, -1);
    for(int i = 0; i < n; ++i) 
    {
        int last = i / len * len;
        for(int j = last; j < i; ++j)
            dp[i] = min(dp[i], dp[j] + dist(i, j));
        if (i - last + 1 == len) 
        {
            for(int j = 0; j < n; ++j) 
                a[j] = 1e18;
            for(int j = last; j <= i; ++j) 
                a[j] = dp[j];
            down(0, -1);
            up(0, -1);
            for(int j = i + 1; j < n; ++j) 
                dp[j] = min({dp[j], dp1[j], dp2[j]});
        }
    }
    for(int i = 0; i < n; ++i) 
        cout << dp[i] << ' ';
}
