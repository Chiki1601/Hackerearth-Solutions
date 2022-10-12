#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>dp(1<<n, 1e18);
        vector<pair<int, int>>a1(n), a2(n);
        for(int i = 0; i < n; i++)
            cin >> a1[i].first >> a1[i].second;
        for(int i = 0; i < n; i++)
            cin >> a2[i].first >> a2[i].second;
        dp[0] = 0;
        for(int mask = 1; mask < (1<<n); mask++)
        {
            int x = __builtin_popcount(mask);
            for(int j = 0; j < n; j++)
            {
                if(mask & (1<<j) == 0)
                    continue;
                dp[mask] = min(dp[mask], dp[mask^(1<<j)] + abs(a1[x - 1].first - a2[j].first) + abs(a1[x - 1].second - a2[j].second));
            }
        }
        cout << dp[(1<<n) - 1];
    }
    return 0;
}
