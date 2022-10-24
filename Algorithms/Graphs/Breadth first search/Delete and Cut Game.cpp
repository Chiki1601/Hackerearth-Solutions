#include <bits/stdc++.h> 
using namespace std; 
long long n, m, u, v, timer;
vector<long long> adj[100002], tin(100002, -1), low(100002, -1), bridges;
vector<bool> vis(100002, 0);
 
long long inverse(long long a)
{
    long long res = 1, pw = 1000000005;
    while (pw)
    {
        if (pw & 1) 
            res = (res * a) % 1000000007;
        a = (a * a) % 1000000007;
        pw >>= 1; 
    }
    return res;
}
 
long long dfs(long long ver, long long par)
{
    long long sz = 1;
    vis[ver] = 1;
    tin[ver] = low[ver] = timer++;
    for (long long &to : adj[ver]) 
    {
        if (to == par)
            continue;
        if (vis[to])
            low[ver] = min(low[ver], tin[to]);
        else
        {
            long long tmp = dfs(to, ver);
            if (low[to] > tin[ver])
                bridges.push_back(tmp);
            low[ver] = min(low[ver], low[to]);
            sz += tmp;
        }
    }
    return sz; 
}
 
void solution()
{
    timer = 0;
    cin >> n >> m;
    for(long i = 0; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    long long eve = 0, tot = bridges.size();
    for(int i = 0; i < bridges.size(); ++i)
    {
        if(bridges[i] % 2 == 0 && (n - bridges[i]) % 2 == 0)
            eve++;
    } 
    long long den = inverse(tot);
    cout << (eve * den) % 1000000007 << " " << ((tot - eve) * den) % 1000000007;
}
 
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(12);
    long t = 1;
    while (t--)
        solution();
    return 0;
}
