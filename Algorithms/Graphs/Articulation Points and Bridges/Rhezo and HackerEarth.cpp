#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>>v[100001];
int vis[100001], low[100001], tin[100001], cnt[100001], t;
 
void dfs(int u, int p)
{
	vis[u] = 1;
	low[u] = tin[u] = t++;
	for(auto it : v[u])
	{
		if(it.first == p)
			continue;
		else if(vis[it.first] == 1)
		low[u] = min(low[u], tin[it.first]);
		else
		{
			dfs(it.first, u);
			if(low[it.first] > tin[u])
				cnt[it.second] = 1;
			low[u] = min(low[u], low[it.first]);
		}
	}
}
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].emplace_back(y, i);
		v[y].emplace_back(x, i);
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == 0)
			dfs(i, -1);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int d;
		cin >> d;
		if(cnt[d] == 1)
			cout << "Unhappy" << endl;
		else
			cout << "Happy" << endl;
	}
}
