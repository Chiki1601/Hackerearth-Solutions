#include<bits/stdc++.h>
using namespace std;
vector<long long int> graph[100009];
 
long long int dfs(long long int node, long long int par, long long int depth)
{
    long long int max_depth = depth;
    for(auto i : graph[node])
    {
        if(i != par)
            max_depth = max(max_depth, dfs(i, node, depth + 1));
    }
    return max_depth;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int i, p, t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i <= 100000; i++)
            graph[i].clear();
        for(i = 1; i < n; i++)
        {
            long long int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        p = dfs(1, 0, 0);
        cout << n + n - p - 2 << endl;
    }
}
