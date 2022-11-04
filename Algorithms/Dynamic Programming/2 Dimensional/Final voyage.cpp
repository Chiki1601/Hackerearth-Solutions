#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005], a[1005], b[1005];
 
long long knapsack(long long n, long long w)
{
	if(n == 0 || w == 0)
		return 0;
	if(dp[n][w] != -1)
		return dp[n][w];
	if(w - a[n - 1] >= 0)
		return dp[n][w] = max(knapsack(n - 1, w - a[n - 1]) + b[n - 1], knapsack(n - 1, w));
	else 
		return dp[n][w] = knapsack(n - 1, w);
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t; 
	cin >> t;
	while(t--)
	{
		long long n, w; 
		cin >> n >> w;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++)
			cin >> b[i];
		memset(dp, -1, sizeof(dp));
		cout << knapsack(n, w) << endl;
	}
	return 0;
}
