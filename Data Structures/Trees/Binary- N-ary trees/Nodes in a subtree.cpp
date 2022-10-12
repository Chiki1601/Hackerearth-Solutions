#include <bits/stdc++.h>
using namespace std;
 
void dfs(int u, int parent, vector<vector<int>> &adj, vector<vector<int>> &freq, string &labels)
{
	freq[u][labels[u - 1] - 'a']++;
	for(auto v: adj[u])
	{
		if(v == parent)
			continue;
		dfs(v, u, adj, freq, labels);
		for(int i = 0; i < 26; ++i)
			freq[u][i] += freq[v][i];
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	string labels;
	cin >> n >> q >> labels;
	vector<vector<int>> freq(n + 1, vector<int>(26, 0)), adj(n + 1);
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, adj, freq, labels);
	while(q--)
	{
		int u;
		char c;
		cin >> u >> c;
		cout << freq[u][c - 'a'] << endl;
	}
}
