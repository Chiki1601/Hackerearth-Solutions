#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj_list;
 
pair<int, int> dfs(int sv, int par) 
{
	pair<int, int> ans({0, 0});
	for (auto child_wt : adj_list[sv]) 
	{
		if (child_wt.first == par) 
			continue;
		pair<int, int> inter = dfs(child_wt.first, sv);
		ans.first = (ans.first + (inter.first + ((((long long)inter.second * child_wt.second) % 1000000007) * ((1 + ans.second) % 1000000007)) % 1000000007 )% 1000000007) % 1000000007;
		ans.second = (ans.second + ((long long)inter.second * child_wt.second) % 1000000007) % 1000000007;
	}
	ans.second++;
	return ans;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	adj_list.resize(n + 1);
	for (int i = 0; i < n - 1; i++) 
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj_list[u].push_back({v, c});
		adj_list[v].push_back({u, c});
	}
	pair<int, int> ans = dfs(1, -1);
	cout << ans.first << endl;
}
