#include <bits/stdc++.h>
using namespace std;
int N, Q, K, ans = 0, color[300010], parent[300010];
vector<int> adj[300010];
unordered_map<int, int> M[300010];
 
void DFS(int node = 1, int prev = 0)
{
    parent[node] = prev;
    for(auto next : adj[node])
    {
        if(next == prev) 
            continue;
        M[node][color[next]]++;
        DFS(next, node);        
    }
}
 
int main()
{    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> Q >> K;
    for(int i = 1; i <= N; i++)
        cin >> color[i];
    adj[1].push_back(2);
    adj[2].push_back(1);
    if(color[1] == color[2]) 
        ans++;
    for(int u = 3, v; u <= N; u++)
    {        
        cin >> v;
        if(color[u] == color[v])
            ans++;
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }        
    DFS();    
    while(Q--)
    {
        int node, c;
        cin >> node >> c;
        if(color[node] == c) 
        {
            cout << ans << endl;
            continue;
        }
        int prev = parent[node];
        if(color[node] == color[prev])           
            ans--;
        else if(color[prev] == c)
            ans++;
        M[prev][color[node]]--;
        M[prev][c]++;
        ans -= M[node][color[node]];
        ans += M[node][c];
        color[node] = c;
        cout << ans << endl;
    }
    return 0;
}
