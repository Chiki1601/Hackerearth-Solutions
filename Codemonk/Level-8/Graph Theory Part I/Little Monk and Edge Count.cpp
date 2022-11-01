#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
int parent[100005], sz[100005];
vector <int> adj[100005];
 
void dfs(int x)
{
    vis[x] = true;
    for(int i = 0; i < adj[x].size(); ++i)
    {
        int y = adj[x][i];
        if(vis[y] == false)
        {
            parent[y] = x;
            dfs(y);
            sz[x] += sz[y];
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q, x, a[100005], b[100005];
    long long ans = 0;
    cin >> n >> q;;
    for(int i = 1; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    parent[1] = -1;
    for(int i = 1; i <= n; ++i)
        sz[i] = 1;
    dfs(1);
    while(q--)
    {
        cin >> x;
        if(parent[a[x]] == b[x])
            ans = (long long)sz[a[x]] * (n - sz[a[x]]);
        else
            ans = (long long)sz[b[x]] * (n - sz[b[x]]);
        cout << ans << "\n";
    }
    return 0;
}
