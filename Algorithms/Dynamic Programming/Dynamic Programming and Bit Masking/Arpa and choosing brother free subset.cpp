#include <bits/stdc++.h>
using namespace std;
int n, k, a[100017], dp[101], old[101];
 
int main()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	a[0] = 1;
	for(int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;
		a[p]++;
	}
	old[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			dp[j] = ((long long) a[i] * (j ? old[j - 1] : 0) + old[j]) % 1000000007;
			if(dp[j] < 0)
				dp[j] += 1000000007;
			if(dp[j] >= 1000000007)
				dp[j] -= 1000000007;
		}
		memcpy(old, dp, sizeof dp);
	}
	cout << dp[k] << endl;
}
