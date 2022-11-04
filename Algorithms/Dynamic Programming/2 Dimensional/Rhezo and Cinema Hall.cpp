#include <bits/stdc++.h> 
using namespace std;  
long long dp[501][5001], C[21][21];
 
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    C[0][0] = 1;
    for(int i = 1; i <= 20; i++)
	{
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
    }
    dp[0][0] = 1;
    int mx = n * m;
    for(int i = 1; i <= n; i++)
	{
        for(int j = 2; j <= mx; j++)
		{
            for(int k = 2; k <= min(m, j); k++)
			{
                if(m - k + 1 >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * C[m - k + 1][k]) % 1000000007;
            }
        }
    }
    long long ans = 0;
    for(int i = max(2, k); i <= mx; i++)
        ans = (ans + dp[n][i]) % 1000000007;
    cout << ans << endl;
    return 0;
}
