#include<bits/stdc++.h>
using namespace std; 
bool vis[100005]; 
vector<int> adj[100005]; 
long long ans = 0;
 
void dfs(int u, int height)
{
    vis[u] = true;
    ans += height; 
    for(int v: adj[u])
	{
        if(!vis[v])
            dfs(v, height + 1);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; 
	cin >> n; 
    for(int i = 0; i < n - 1; i++)
	{
        int a, b; 
		cin >> a >> b; 
		a--, b--; 
		adj[a].push_back(b); 
		adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++)
		vis[i] = false;
    dfs(0, 1);
    cout << ans << endl; 
    return 0;
}
