#include <bits/stdc++.h>
using namespace std;
vector <int> G[200005];
int min_dist[200005];
 
void add_edge(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        add_edge(2 * a, 2 * b + 1);
    }
    for(int i = 1; i <= n; ++i)
    {
        add_edge(2 * i, 2 * i + 1);
        min_dist[2 * i] = 1500000000;
        min_dist[2 * i + 1] = 1500000000;
    }
    queue <int> bfs;
    bfs.push(2);
    min_dist[2] = 0;
    while(!bfs.empty())
    {
        int top = bfs.front();
        bfs.pop();
        for(int i = 0; i < G[top].size(); ++i)
        {
            if(min_dist[G[top][i]] == 1500000000)
            {
                min_dist[G[top][i]] = min_dist[top] + 1;
                bfs.push(G[top][i]);
            }
        }
    }
    int ans_time = min(min_dist[2 * n], min_dist[2 * n + 1]);
    while(q--)
    {
        int t;
        cin >> t;
        if(ans_time <= t)
            cout << "GGMU" << endl;
        else
            cout << "FML" << endl;
    }
    return 0;
}
