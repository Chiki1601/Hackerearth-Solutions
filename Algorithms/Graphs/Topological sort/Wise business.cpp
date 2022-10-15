#include <bits/stdc++.h>
using namespace std;
 
void dfs(auto &v, int node, auto &vis, auto &w, auto &profit) 
{
    if(vis[node])
        return;
    vis[node] = true;
    for(int i : v[node]) 
    {
        dfs(v, i, vis, w, profit);
        profit[node] = max(profit[node], profit[i] + w[i] - w[node]);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, x, y, total = 0;
        cin >> n >> m;
        vector<vector<int>> v(n + 1);
        vector<int> w(n + 1, -1), profit(n + 1, 0);
        vector<bool> vis(n + 1, false);
        for(int i = 1; i <= n; i++) 
            cin >> w[i];
        for(int i = 0; i < m; i++) 
        {
            cin >> x >> y;
            v[x].push_back(y);
        }
        for(int i = 1; i <= n; i++) 
        {
            dfs(v, i, vis, w, profit);
            total = max(profit[i], total);
        }
        cout << total << endl;
    }
    return 0;
}
