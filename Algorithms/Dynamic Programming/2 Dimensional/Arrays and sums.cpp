#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int t, n, a[10014], dp[10014], tmp[10014];
    cin >> t;
    while(t--)
    {
        cin >> n;
        fill(dp, dp + 10014, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            for(int j = 10013; j >= a[i]; j--)
            {
                dp[j] += dp[ j - a[i] ];
                if(dp[j] >= 1000000007)  
                    dp[j] -= 1000000007;
            }
        memcpy(tmp, dp, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            memcpy(dp, tmp, sizeof dp);
            for(int x = a[i]; x < 10014; x++)
            {
                dp[x] += 1000000007 - dp[ x - a[i] ];
                if(dp[x] >= 1000000007)  
                    dp[x] -= 1000000007;
            }
            cout << (!a[i] || dp[a[i]]) << ' ';
        }
        cout << endl;
    }
}
