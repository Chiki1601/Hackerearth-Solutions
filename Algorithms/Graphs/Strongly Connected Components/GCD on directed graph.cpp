#include<bits/stdc++.h>
using namespace std; 
stack<int> finished;
bool visited[100005];
set<int> comp[100005], gcds[100005];
vector<int> adj[100005], rev[100005];
int Cost[100005], id = 0, ID[100005], Value[100005];
 
void dfs1(int u)
{
    visited[u] = true; 
    for(int v : adj[u])
        if(!visited[v])
            dfs1(v);
    finished.push(u);
}
 
int dfs2(int u)
{
    int gcdValue = Cost[u]; 
    ID[u] = id;
    visited[u] = true; 
    for(int v : rev[u])
        if(!visited[v])
            gcdValue = __gcd(gcdValue, dfs2(v));
    return gcdValue;
}
 
void dfs3(int u)
{
    visited[u] = true;
    gcds[u].insert(Value[u]);
    for(int v : comp[u])
    {
        if(!visited[v])
            dfs3(v);
        for(int x : gcds[v])
            gcds[u].insert(__gcd(Value[u], x));
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; 
    cin >> n >> m; 
    for(int i = 0; i < n; i++)
        cin >> Cost[i];
    for(int i = 0; i < m; i++)
    {
        int u, v; 
        cin >> u >> v; 
        u--, v--; 
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
        visited[i] = false;
    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs1(i);
    for(int i = 0; i < n; i++)
        visited[i] = false;
    while(!finished.empty())
    {
        int u = finished.top(); 
        finished.pop(); 
        int minGCD = Cost[u];
        if(!visited[u])
            Value[id++] = min(minGCD, dfs2(u));
    }
    for(int i = 0; i < n; i++)
    {
        for(int v: adj[i])
        {
            int idI = ID[i], idV = ID[v];
            if(idI != idV)
              comp[idI].insert(idV);
        }
    }
    for(int i = 0; i < id; i++)
        visited[i] = false;
    for(int i = 0; i < id; i++)
        if(!visited[i])
            dfs3(i);
    int minGCD = Value[0];
    for(int i = 0; i < id; i++)
    {
        if(!gcds[i].empty())
            minGCD = min(minGCD, *gcds[i].begin());
    }
    cout << minGCD << endl;
    return 0;
}
