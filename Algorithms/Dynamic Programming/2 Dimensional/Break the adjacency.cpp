#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n; 
    cin >> t;
    while(t--)
    {     
        cin >> n;
        vector<int> a(n), prices(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> prices[i];
        vector<vector<int>> dp(n, vector<int>(3, (int)1e15));
        dp[0][0] = 0;
        dp[0][1] = prices[0];
        dp[0][2] = 2 * prices[0];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= 2; j++)
            {
                for(int k = 0; k <= 2; k++)
                {
                    int curlen = a[i] + j;
                    int prevlen = a[i - 1] + k;
                    if(curlen != prevlen)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * prices[i]);
                }
            }
        }
        int ans = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
        cout << ans << "\n";
    }
    return 0;
}
