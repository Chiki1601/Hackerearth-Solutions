#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, dp[100005];
    long long ans;
    string s;
    cin >> t;
    while(t--)
    {
        map <int, long long> m;
        cin >> s;
        n = s.length();
        dp[0] = 0;
        ans = 0;
        for(int i = 1; i <= n; ++i) 
            dp[i] = dp[i - 1] ^ (1 << (s[i - 1] - 97));
        m[dp[0]]++;
        for(int i = 1; i <= n; ++i)
        {
            ans += m[dp[i]];
            ++m[dp[i]];
        }
        cout << ans << endl;
    }
    return 0;
}
