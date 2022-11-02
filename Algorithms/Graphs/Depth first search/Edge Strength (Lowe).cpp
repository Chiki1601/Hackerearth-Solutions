#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
int sz[100001];
 
void dfs(int s, int par)
{
    sz[s] = 1;
    for(int i = 0; i < adj[s].size(); i++)
    {
        if(adj[s][i] != par)
        {
            dfs(adj[s][i], s);
            sz[s] += sz[adj[s][i]];
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y; 
    pair<int, int>edges[n];
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i < n; i++)
        cout << sz[edges[i].second]*1LL*(n - sz[edges[i].second]) << endl;
}
