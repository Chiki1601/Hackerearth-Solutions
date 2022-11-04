#include <bits/stdc++.h>
using namespace std; 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, i, j, ans, a[1005][1005], dp[1005][1005];
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				cin >> a[i][j];
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(i == 0 or j == 0)
					dp[i][j] = 1;
				else
				{
					if(a[i][j] == a[i - 1][j] and a[i][j] == a[i - 1][j - 1] and a[i][j] == a[i][j - 1])
						dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					else
						dp[i][j] = 1;
				}
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
