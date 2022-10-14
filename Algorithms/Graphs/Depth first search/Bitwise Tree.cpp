#include<bits/stdc++.h>
using namespace std;
int n, a[100002][11], dp[100002][11];
vector<int> g[100002];
 
void dfs(int v, int p) 
{
	for(int u : g[v]) 
	{
		if(u != p) 
			dfs(u, v);
	}
	for(int i = 0; i < 11; i++) 
	{
		int cur = i;
		for(int u : g[v]) 
		{
			if(u != p) 
			{
				int mn = n * 30;
				for(int j = 0; j < 11; j++) 
				{
					if((a[v][i] & a[u][j]) == 0) 
						mn = min(mn, dp[u][j]);
				}
				cur += mn;
			}
		}
		dp[v][i] = cur;
	}
}
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i][0];
		for(int j = 1; j < 11; j++) 
			a[i][j] = a[i][j - 1] / 2;
	}
	for(int i = 0; i < n - 1; i++) 
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	int ans = n * 30;
	for(int i = 0; i < 11; i++) 
		ans = min(ans, dp[1][i]);
	cout << ans << "\n";
	return 0;
}
