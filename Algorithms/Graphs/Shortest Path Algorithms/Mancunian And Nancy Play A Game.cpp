#include <bits/stdc++.h>
using namespace std;
vector <int> G[100005];
 
void bfs(int src, int n, int cd[])
{
    for(int i = 1; i <= n; ++i)
        cd[i] = 1000000009;
    cd[src] = 0;
    queue <int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        for(int i = 0; i < G[top].size(); ++i)
        {
            if(cd[G[top][i]] == 1000000009)
            {
                cd[G[top][i]] = cd[top] + 1;
                Q.push(G[top][i]);
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k, m1, m2, ans = 0, q, dist1[100005], dist2[100005];
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> m1 >> m2;
    bfs(m1, n, dist1);
    bfs(m2, n, dist2);
    cin >> q;
    while(q--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if(dist1[n1] <= k && dist2[n2] <= k && dist1[m2] != 1000000009)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
