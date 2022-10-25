#include <bits/stdc++.h>
using namespace std;
int n, p1, p2, q, depth[100005], pa[100005][20], size[100005];
long long sum[100005][20];
vector <int> adj[100005];
 
int dfs(int v, int p, int d)
{
    depth[v] = d;
    pa[v][0] = p;
    for(int x = 0; pa[v][x]; x++) 
        pa[v][x + 1] = pa[pa[v][x]][x];
    size[v] = 1;
    for(int x = 0; x < adj[v].size(); x++)
    {
        if(adj[v][x] == p) 
            continue;
        size[v] += dfs(adj[v][x], v, d + 1);
    }
    return size[v];
}
 
void dfs2(int v, int p)
{
    if(v > 1) 
        sum[v][0] = (long long)(size[pa[v][0]] - size[v]) * (long long)(size[pa[v][0]] - size[v] - 1) / 2ll;
    for(int x = 1; pa[v][x - 1]; x++) 
        sum[v][x] = sum[v][x - 1] + sum[pa[v][x - 1]][x - 1];
    for(int x = 0; x < adj[v].size(); x++)
    {
        if(adj[v][x] == p) 
            continue;
        dfs2(adj[v][x], v);
    }
}
 
long long lca(int a, int b)
{
    if(a == b) 
        return (long long)(n) * (long long)(n - 1) / 2ll;
    long long ans = 0ll;
    if(depth[a] > depth[b]) 
        a ^= b ^= a ^= b;
    int sa = a, sb = b;
    if(depth[a] < depth[b])
    {
        for(int x = 0; x < 17; x++)
        {
            if((1 << x) & (depth[b] - depth[a] - 1))
            {
                ans += sum[b][x];
                b = pa[b][x];
            }
        }
        if(a == pa[b][0]) 
            return ans + (long long)(size[sb]) * (long long)(size[sb] - 1) / 2ll + (long long)(n - size[b]) * (long long)(n - size[b] - 1) / 2ll;
        ans += sum[b][0];
        b = pa[b][0];
    }
    for(int x = 16; x >= 0; x--)
    {
        if(pa[a][x] != pa[b][x])
        {
            ans += sum[a][x] + sum[b][x];
            a = pa[a][x];
            b = pa[b][x];
        }
    }
    long long k = (long long)(n - size[a] - size[b]);
    return ans + k * (k - 1ll) / 2ll + (long long)(size[sa]) * (long long)(size[sa] - 1) / 2ll + (long long)(size[sb]) * (long long)(size[sb] - 1) / 2ll;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int x = 0; x < n - 1; x++)
    {
        cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }
    dfs(1, 0, 0);
    dfs2(1, 0);
    cin >> q;
    while(q--)
    {
        cin >> p1 >> p2;
        cout << (long long)(n) * (long long)(n - 1) / 2ll - lca(p1, p2) << endl;
    }
}
