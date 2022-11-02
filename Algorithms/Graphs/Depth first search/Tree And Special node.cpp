#include<bits/stdc++.h>
using namespace std;
 
void dfs(vector<bool>& hc, vector<vector<int>>& adj, vector<int> & a, int& ans, int u) 
{
    if(!hc[a[u]]) 
        ++ ans;
    else 
        return;
    hc[a[u]] = true;
    for(int v : adj[u]) 
	{
        if(v == u) 
            continue;
        dfs(hc, adj,a, ans, v);
    }
    hc[a[u]] = false;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0, x, y;
    unordered_set<int> s;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> a(n);
    vector<bool> hc(1000001);
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    for(int i = 0; i < n - 1; ++i) 
	{
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    dfs(hc, adj, a, ans, 0);
    cout << ans << endl;
    return 0;
}
