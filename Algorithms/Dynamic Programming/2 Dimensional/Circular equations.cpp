#include <bits/stdc++.h>
using namespace std;
int n, dp[20][200];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[0][0] = 1;
    for(int i = 1; i < 20; i++)
        for(int j = 0; j < 200; j++)
            for(int ld = 0; ld < 10 && j - ld >= 0; ld++)
                (dp[i][j] += dp[i - 1][j - ld]) %= 1000000007;
				int q;
    cin >> q;
    while(q--)
	{
        long long s;
        cin >> s;
        int ans = 0;
        for(long long pat = 1, n = 1; pat <= s; pat = pat * 10 + 1, n++)
            if(s % pat == 0 && n * 9 >= s / pat)
                (ans += dp[n][s / pat]) %= 1000000007;
        cout << ans << endl;
    }
}
