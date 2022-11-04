#include <bits/stdc++.h>
using namespace std;
long long  arr[10005], dp[1005][10005];
 
void solve()
{
	int n, k, m;
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int j = 0; j < k + 1; j++)
	{
		if(j == 0)
			continue;
		for(int i = 0; i < n; i++)
		{
			if(j > i + 1)
				dp[j][i] = -1e18;
			else
			{
				if(i == 0)
					dp[j][i] = arr[i];
				else 
					dp[j][i] = max(dp[j][i - 1], dp[j - 1][i - 1] + arr[i] * (j % m));
			}
		}
	}
	cout << dp[k][n - 1] << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	while(t--)
		solve();	
	return 0;
}
