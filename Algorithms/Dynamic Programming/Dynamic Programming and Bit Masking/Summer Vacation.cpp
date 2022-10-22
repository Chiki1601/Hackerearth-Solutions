#include <bits/stdc++.h>
using namespace std;
 
int numberOfWays(int n, int D, vector<int> &t, vector<int> &g)
{
    int dp[1 << n][4] = {0}, ans = 0;
    dp[0][3] = 1;
    for(int i = 0; i < 1<<n; i++)
	{
        for(int last = 0; last < 4; last++)
		{
            for(int j = 0; j < n; j++)
			{
                if(g[j] != last && ((i & (1 << j)) == 0))
                    dp[i + (1 << j)][g[j]] = (dp[i + (1 << j)][g[j]] + dp[i][last]) % 1000000007;
            }
            int sum = 0;
            for(int j = 0; j < n; j++)
			{
                if(i & ( 1 << j))
                    sum += t[j];
            }
            if(sum == D)
                ans = (ans + dp[i][last]) % 1000000007;
        }
    }
    return ans;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, D;
        cin >> n >> D;
        vector<int> t(n), g(n);
        for(int i = 0; i < n; i++)
            cin >> t[i] >> g[i];
        cout << numberOfWays(n, D, t, g) << "\n";
    }
}
