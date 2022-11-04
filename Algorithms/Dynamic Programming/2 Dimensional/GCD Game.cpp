#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int dp[2][1001][1001], t, a, b;
	for(int i = 1; i <= 1000; i++)
	{
		dp[0][1][i] = dp[1][1][i] = 0;
		dp[0][i][1] = dp[1][i][1] = 1;
	}
	for(int i = 2; i <= 1000; i++)
	{
		for(int j = 2; j <= 1000; j++)
		{
			dp[0][i][j] = dp[1][i][j - 1];
			dp[1][i][j] = dp[0][i - 1][j];
			if(__gcd(i, j) > 1)
			{
			 	dp[0][i][j] = max(dp[0][i][j], dp[1][i][j / __gcd(i, j)]);
			 	dp[1][i][j] = min(dp[1][i][j], dp[0][i / __gcd(i, j)][j]);
			}
		}
	}
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		if(a == 1 and b == 1)
			cout << "Draw" << endl;
		else
			cout << (dp[0][a][b] ? "Arjit" : "Chandu Don") << endl;
	}
	return 0;
}
