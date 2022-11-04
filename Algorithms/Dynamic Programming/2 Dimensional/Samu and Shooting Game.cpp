#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tt, x, y, p, pp, n, w; 
	cin >> tt;
    while(tt--)
    {
		cin >> x >> y >> n >> w >> p >> pp;
		vector<vector<double>> dp(n + 1, vector<double>(w + 1, 0));
		for(int i = 0; i <= n; i++)
			dp[i][0] = 1;
		double p1 = 0.01 * p, p2 = 0.01 * pp;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= w; j++)
			{
				dp[i][j] = dp[i - 1][max(j - x, 0)] * p1 + dp[i - 1][j] * (1 - p1);
				dp[i][j] = max(dp[i][j], dp[i - 1][max(j - y, 0)] * p2 + dp[i - 1][j] * (1 - p2));
			}
		}
		cout << setprecision(6) << fixed << dp[n][w] * 100 << endl;
	}
    return 0;
}
