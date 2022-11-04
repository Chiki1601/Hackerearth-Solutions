#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int t; 
    cin >> t; 
    while(t--)
    {
        long long int n; 
        cin >> n;
        vector<long long int>t(n), c(n);
        for(int i = 0; i < n; i++)
        {
            cin >> t[i] >> c[i];
            t[i]++;
        }
        vector<long long int>dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for(long long int i = 0; i < n; i++)
        {
            for(long long int j = n; j >= 0; j--)
            {
                if(dp[j] != LLONG_MAX)
                {
                    long long int x = j + t[i];
                    if(x > n) 
                        x = n;
                    dp[x] = min(dp[x], dp[j] + c[i]);
                }
            }
        }
        cout << dp[n] << endl;
    }
	return 0;
}
