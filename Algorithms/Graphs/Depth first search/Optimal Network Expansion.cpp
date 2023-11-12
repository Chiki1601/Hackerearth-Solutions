#include <bits/stdc++.h>
using namespace std;
int vis[100002];
vector<int> adj[100002];

void dfs(int node, vector<int> &aux)
{
    aux.push_back(node);
    vis[node] = 1;
    for(auto val : adj[node])
	{
        if(vis[val] == 0)
            dfs(val, aux);
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k, sum = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) 
	{
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, 0, sizeof vis);
	vector<pair<int, vector<int>>> ans;
    for(int i = 1; i <= n; i++) 
	{
        if(vis[i] == 0) 
		{
            vector<int> aux;
            dfs(i, aux);
            ans.push_back({aux.size(), aux});
        }
    }
    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i <= k; i++) 
        sum += ans[i].first;
    cout << sum << "\n";
    return 0;
}
