#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, k;
	long long dp[1002][1002];
	dp[0][1000] = 1;
	for(int k = 999; k > 0; k--) 
	{
		for(int i = 0; i <= 999; i++) 
		{
			dp[i][k] = dp[i][k + 1];
			if(i - k >= 0) 
				dp[i][k] = (dp[i][k] + dp[i - k][k]) % 1000000009;
		}
	}
	cin >> t;
	while(t--) 
	{
		cin >> n >> k;
		long long ans = dp[n][k];
		cout << ans << endl;
	}
	return 0;
}
