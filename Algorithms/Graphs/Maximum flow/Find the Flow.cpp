#include <bits/stdc++.h>
using namespace std;
int cap[100][100], flow[100][100], parent[100];
vector<int> graph[100];
 
void addEdge(int u, int v, int w) 
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    cap[u][v] = w;
}
 
int bfs(int s, int t) 
{
    memset(parent, -1, sizeof(parent));
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 1000000000});
    while (!q.empty()) 
    {
        int u = q.front().first, f = q.front().second;
        q.pop();
        for(int v : graph[u]) 
        {
            if(parent[v] == -1 && cap[u][v] > flow[u][v]) 
            {
                parent[v] = u;
                int newFlow = min(f, cap[u][v] - flow[u][v]);
                if(v == t)
                    return newFlow;
                q.push({v, newFlow});
            }
        }
    }
    return 0;
}
 
int edmondsKarp(int s, int t) 
{
    int newFlow, sumFlow = 0, cnt = 0;
    while((newFlow = bfs(s, t)) != 0) 
    {
        sumFlow += newFlow;
        int prev, cur = t;
        while(cur != s) 
        {
            prev = parent[cur];
            flow[prev][cur] += newFlow;
            flow[cur][prev] -= newFlow;
            cur = prev;
        }
    }
    return sumFlow;
}
 
int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, s, t;
    cin >> m;
    for(int w, i = 0; i < m; i++) 
    {
        char u, v;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    cout << edmondsKarp('S', 'T');
    return 0;
}
