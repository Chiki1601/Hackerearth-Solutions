#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n; 
	cin >> n;
	long long a[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	long long dp[n][n];
	for(int i = 0; i < n; i++)
		dp[0][i] = a[0][i];
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			long long maxx = dp[i - 1][j];
			if(j + 1 < n)
				maxx = max(maxx, dp[i - 1][j + 1]);
			if(j - 1 >= 0)
				maxx = max(maxx, dp[i - 1][j - 1]);
			dp[i][j] = maxx + a[i][j];
		}
	}
	long long maxx = LONG_LONG_MIN;
	for(int i = 0; i < n; i++)
		maxx = max(dp[n - 1][i], maxx);
	cout << maxx << endl;
	return 0;
}
