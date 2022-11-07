#include<bits/stdc++.h>
using namespace std;
long long n, m, t, k, dp[100001]; 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n;
    for(int i = 0; i <= 100001; i++)
        dp[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        a = a * 60 + b;
        c = c * 60 + d + 5;
        dp[a]++;
        dp[c]--;
    }
    long long ans = 0;
    for(int i = 1; i <= 100000; i++)
    {  
        dp[i] += dp[i - 1];
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}
