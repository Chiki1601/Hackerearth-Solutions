#include <bits/stdc++.h>
using namespace std;
int n, tot_ans = 1;
vector<int> g[100014];
 
int dfs(int v = 0, int p = -1) 
{
	int ans = 1;
	for(auto u : g[v])
		if(u != p)
			ans = (long long) ans * dfs(u, v) % 1000000007;
	(tot_ans += ans) %= 1000000007;
	return ans + 1;
}
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; ++i) 
	{
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs();
	cout << tot_ans << endl;
}
