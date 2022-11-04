#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	long long mod = pow(10, 9) + 7;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; cin >> a[i++]);
		long long dp[n][100];
		memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++)
	{
		dp[i][a[i]] = 1;
		for(int j = i - 1; j >= 0; j--)
		{
			if(a[i] > a[j])
			{
				for(int k = 1; k <= 100; k++)
				{
					int g = __gcd(a[i], k);
					dp[i][g] = (dp[i][g] % mod + dp[j][k] % mod) % mod;
				}
			}
		}
	}
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum = (sum + dp[i][1]) % mod;
	cout << sum;
}
