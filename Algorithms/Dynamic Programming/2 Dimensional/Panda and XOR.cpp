#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, cur = 0, pre = 1, a[100005];
    cin >> n;
    assert(1 <= n && n <= 100000);
    long long ans = 0, dp[2][128];
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        assert(0 <= a[i] && a[i] <= 100);
    }
    dp[cur][0] = 1;
    for(i = 0; i < n; i++)
    {
        pre = cur;
        cur ^= 1;
        for(j = 0; j < 128; j++)
            dp[cur][j] = (dp[pre][j] + dp[pre][j ^ a[i]]) % 1000000007;
    }
    dp[cur][0]--;
    for(i = 0; i < 128; i++)
    {
        long long cnt = dp[cur][i];
        long long ways = (cnt - 1 + 1000000007) % 1000000007;
        ways = (ways * cnt) % 1000000007;
        ways = (ways * 500000004) % 1000000007;
        ans += ways;
        if(ans >= 1000000007)
        	ans -= 1000000007;
    }
    cout << ans << endl;
    return 0;
}
