#include <bits/stdc++.h>
using namespace std; 
int weight[100005], timer, max_height, tin[100005], tout[100005];
vector<int> adj[100005];
vector<pair<int, long long>> heights[100005];
vector<pair<int, long long>>::iterator it1, it2;
 
void dfs(int u, int p, int h) 
{
	tin[u] = ++timer;
	max_height = max(max_height, h);
	heights[h].push_back({tin[u], weight[u]});
	for(auto v : adj[u]) 
    {
		if (v != p) 
			dfs(v, u, h + 1);
	}
	tout[u] = ++timer;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n, m, x, y;
	long long ans;
	cin >> t;
	while(t--) 
    {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) 
			cin >> weight[i];
		for(int i = 1; i < n; ++i) 
        {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		timer = 0;
		dfs(1, -1, 1);
		for(int i = 1; i <= max_height; ++i) 
        {
			for(int j = 1; j < heights[i].size(); ++j) 
				heights[i][j].second += heights[i][j - 1].second;
		}
		while(m--) 
        {
			cin >> x >> y;
			if(y > max_height) 
				ans = 0;
			else 
            {
				pair<int, long long> a = {tin[x], -1}, b = {tout[x], -1};
				it1 = lower_bound(heights[y].begin(), heights[y].end(), a);
				it2 = upper_bound(heights[y].begin(), heights[y].end(), b);
				it2--;
				ans = it2->second;
				if(it1 != heights[y].begin()) 
                {
					it1--;
					ans -= it1->second;
				}
			}
			cout << ans << "\n";
		}
		for(int i = 1; i <= n; ++i) 
			adj[i].clear();
		for(int i = 1; i <= max_height; ++i) 
			heights[i].clear();
	}
	return 0;
}
