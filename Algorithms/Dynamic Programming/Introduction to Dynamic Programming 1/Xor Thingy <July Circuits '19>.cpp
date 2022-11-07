#include<bits/stdc++.h>
using namespace std;
int n, m, dp[519], tdp[519];
 
int main()
{
    cin >> n >> m;
    dp[0] = 1;
    for (; n; n --)
    {
        int a;
        cin >> a;
        memset(tdp, 0, sizeof(tdp));
        for (int i = 0; i <= a; i ++)
            for (int j = 0; j < 512; j ++)
            {
                tdp[i ^ j] += dp[j];
                if (tdp[i ^ j] >= 1000000007)
                    tdp[i ^ j] -= 1000000007;
            }
        memcpy(dp, tdp, sizeof(dp));
    }
    for (int i = 0; i <= m; i ++)
        cout << dp[i] << " ";
    return 0;
}
