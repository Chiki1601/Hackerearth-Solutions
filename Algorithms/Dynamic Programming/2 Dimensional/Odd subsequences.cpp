#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int t; 
    cin >> t; 
    while(t--)
    {
        long long int n, s; 
        cin >> n >> s;
        vector<long long int>a(n + 1);
        for(int i = 1; i <= n; i++) 
            cin >> a[i];
        vector<vector<vector<long long int>>>dp(n + 1, vector<vector<long long int>>(n + 1, vector<long long int>(2, 0)));
        dp[0][0][1] = 1;
        for(long long int i = 1; i <= n; i++)
        {
            for(long long int j = 0; j <= n; j++)
            {
                for(long long int k = 0; k < 2; k++)
                    dp[i][j][k] = dp[i - 1][j][k];
            }
            for(long long int j = 1; j <= n; j++)
            {
                for(long long int k = 0; k < 2; k++)
                {
                    if(a[i] % 2 == 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k]) % 1000000007;
                    else
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k^1]) % 1000000007;
                }
            }
        }
        cout << dp[n][s][0] << endl;
    }
	return 0;
}
