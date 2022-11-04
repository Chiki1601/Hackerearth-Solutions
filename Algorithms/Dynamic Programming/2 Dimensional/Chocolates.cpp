#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000];
 
string solve()
{
	bool dp[1000][1000];
    for(int i = 0; i < n; i++)
        dp[i][i] = true;
    for(int len = 1; len < n; len++)
	{
        for(int i = 0; i + len < n; i++)
		{
            int j = i + len;
            if(a[i] != a[j])
                continue;
            for(int l = 1; l <= k; l++)
			{
                for(int p = 1; p <= k; p++)
				{
                    if(i + l <= j - p)
                        dp[i][j] |= dp[i + l][j - p];
                }
            }
        }
    }
    return (dp[0][n - 1] ? "YES" : "NO");
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve();
    return 0;
}
