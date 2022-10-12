using namespace std;
#include <bits/stdc++.h>
long long n, dp[5100][15][15], c[15], values[15];
 
long long f(long long mask, long long fir, long long sec)
{
    if(dp[mask][fir][sec] != -1)
        return dp[mask][fir][sec];
    long long done = __builtin_popcount(mask), xo = values[fir] ^ values[sec], ans = 1000000000;
    if(done == n)
        return 0;
    for(long long i = 0; i < n; i++)
    {
        if(mask & (1 << i))
            continue;
        ans = min(ans, f(mask | (1 << i), i, fir) + (values[i] ^ xo) * c[done]);
    }
    return dp[mask][fir][sec] = ans;
}
 
int main()
{
    long long t = 1;
    cin >> t;
    while(t--)
    {
		long long ans = 1000000000;
		cin >> n;
		for(long long i = 0; i < n; i++)
			cin >> values[i];
		for(long long i = 0; i < n; i++)
			cin >> c[i];
		memset(dp, -1, sizeof(dp));
		for(long long i = 0; i < n; i++)
		{
			for(long long j = 0; j < n; j++)
			{
				if(i == j)
					continue;
				long long mask = ((1 << i) | (1 << j));
				ans = min(ans, f(mask, i, j));
			}
		}
		cout << ans << endl;
	}
    return 0;
}
