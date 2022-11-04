#include<bits/stdc++.h>
using namespace std;
long long grid[1010][1010], dp[1010][1010], cnt[100010], prime[100010];
 
void preprocess()
{
	for (long long i = 2; i < 100010; i++)
		cnt[i] = 1, prime[i] = i;
	for (long long i = 2; i < 100010; i += 2LL)
		prime[i] = 2LL;
	for (long long i = 3LL; i * i < 100010; i++)
	{
		if (prime[i] != i)
			continue;
		for (long long j = i * i; j < 100010; j += i)
		{
			if (prime[j] != j)
				continue;
			prime[j] = i;
		}
	}
	for (long long i = 2LL; i < 100010; i++)
		cnt[i] = cnt[i / prime[i]] + 1LL;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	preprocess();
	long long t; 
    cin >> t;
	while (t--)
	{
		long long n, m ; 
        cin >> n >> m;
 		for (long long i = 0; i < n; i++)
		{
			for (long long j = 0; j < m; j++)
			{
				long long x; 
                cin >> x;
				grid[i][j] = cnt[x];
			}
		}
 		for (long long i = 0; i < n; i++)
		{
			for (long long j = 0; j < m; j++)
				dp[i][j] = 1e18;
		}
		dp[0][0] = grid[0][0];
		for (long long i = 0; i < n; i++)
		{
			for (long long j = 0; j < m; j++)
			{
				if (i == 0 && j == 0)
					continue;
				if (i - 1 >= 0)
					dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j]);
				if (j - 1 >= 0)
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
			}
		}
		cout << dp[n - 1][m - 1] << endl;
	}
	return 0;
}
