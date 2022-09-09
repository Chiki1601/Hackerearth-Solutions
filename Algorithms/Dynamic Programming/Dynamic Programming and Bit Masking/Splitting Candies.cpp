#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	int t = 1;
	while(t--) 
	{
        int n, k;
        cin >> n >> k; 
        int a[n + 1];
        for(int i = 1; i <= n; i++) 
            cin >> a[i];
        vector<int> frq(5, 0), pre(n + 1), dp(n + 1, 1000000007);
        for(int i = 1; i <= n; i++)
        {
            frq[a[i]]++;
            for(int j = 1; j <= 5; j++)
                if(frq[j] % 2) 
                    pre[i] += (1ll << j);
        }
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = max(1, i - k + 1); j <= i; j++)
            {
                int x = pre[i] ^ pre[j - 1];
                if(x & (x - 1)) 
                    continue;
                dp[i] = min(dp[i], dp[j - 1] + a[i] + a[j]);
            }
        }
        cout << dp[n] % 1000000007 << "\n";
    }
	return 0; 
}
