#include <bits/stdc++.h>
using namespace std;
vector<int> g[200014], ord;
bool mark[200014];
 
void dfs(int v)
{
    if(mark[v])
        return ;
    mark[v] = true;
    for(auto u : g[v])
        dfs(u);
    ord.push_back(v);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, dp[200014];
    cin >> n >> m;
    for(int i = 0; i < m; i++)
	{
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
    }    
    for(int i = 0; i < n; i++)
        dfs(i);
    for(auto v : ord)
	{
        dp[v] = 1;
        for(auto u : g[v])
            dp[v] = max(dp[v], dp[u] + 1);
    }
    cout << *max_element(dp, dp + n) << endl;
}
