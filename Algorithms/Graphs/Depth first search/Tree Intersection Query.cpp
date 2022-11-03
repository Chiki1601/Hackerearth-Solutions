#include<bits/stdc++.h>
using namespace std;
vector<int> graph[200005], inValues[200005];
int in[200005], out[200005], timer;
 
void dfs(int v, int par = 0) 
{
	in[v] = ++timer;
	for(int u : graph[v]) 
	{
		if(u != par) 
			dfs(u, v);
	}
	out[v] = ++timer;
	for(int u : graph[v]) 
	{
		if(u != par) 
			inValues[v].push_back(in[u]);
	}
}
 
bool isAnc(int u, int v) 
{
  	return (in[u] <= in[v] && out[u] >= out[v]);
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	while(T--)
	{
		int n, q;
		cin >> n >> q;
		for(int i = 2; i <= n; i++) 
		{
			int x, y; 
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		timer = 1;
		dfs(1);
		while(q--) 
		{
			int x, k;
			cin >> x >> k;
			long long answer = 1LL * k * (k - 1) / 2;
			map<int, int> cnt;
			for(int i = 0; i < k; i++) 
			{
				int nd; 
				cin >> nd;
				if(nd == x) 
					continue;
				if(isAnc(x, nd)) 
				{
					int subtree = upper_bound(inValues[x].begin(), inValues[x].end(), in[nd]) - inValues[x].begin();
					cnt[subtree]++;
				} 
				else 
					cnt[n + 1]++;
			}
			for(auto u : cnt) 
				answer -= 1LL * u.second * (u.second - 1) / 2;
			cout << answer << "\n";
		}
	}
	return 0;
}
