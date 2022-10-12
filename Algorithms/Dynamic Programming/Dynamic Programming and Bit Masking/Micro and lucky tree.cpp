#include<bits/stdc++.h>
using namespace std;
int n, m, bit[300] = {0};
long long dp[300][100100];
vector<int> v[100100];
 
long long dfs(int x, int par, int mask)
{
	if(dp[mask][x] != -1)
		return dp[mask][x];
	long long ret = 0;
	for(int i = 1; i <= m; i++)
	{
		int flag = 1;
		long long p = 1;
		for(int j = 0; j < v[x].size(); j++)
		{
			if(v[x][j] == par)
				continue;
			p = (p * dfs(v[x][j], x, mask & bit[i])) % 1000000007;
			flag = 0;
		}
		if(flag)
		{
			if((mask & bit[i]) == 0)
				ret++;
		}
		else
			ret = (ret + p) % 1000000007;
	}
	return dp[mask][x] = ret;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		long long x, y; 
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int arr[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < 8; j++)
			if(i % arr[j] == 0)
				bit[i]|=(1<<j);
	}
	cout << dfs(1, -1, 255) << endl;
	return 0;
}
