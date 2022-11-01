#include<bits/stdc++.h> 
using namespace std;
bool visited[100005];
vector<int> g[100005];
int a[100005], ans[100005][33];
     
void dfs(int u) 
{
    visited[u] = 1;
    for(int i = 0; i < g[u].size(); i++) 
    {
        int v = g[u][i];
        if(!visited[v]) 
        {
            dfs(v);
            for(int j = 0; j < 32; j++) 
                ans[u][j] = max(ans[u][j], ans[v][j]);
        }
    }
    for(int i = 0; i < 32; i++) 
    {
        if(a[u] & (1<<i)) 
        {
            if(ans[u][i] % 2 == 0) 
                ans[u][i]++;
        }
        else 
        {
            if(ans[u][i] % 2 == 1) 
                ans[u][i]++;
        }
    }
}
     
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, A, ret = 0;
    cin >> n >> A;
    for(int i = 0; i < n - 1; i++) 
    {
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    dfs(A);
    for(int i = 0; i < 32; i++) 
        ret += ans[A][i];
    cout << ret << "\n";
}
