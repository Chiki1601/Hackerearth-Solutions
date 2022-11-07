#include<bits/stdc++.h>
using namespace std;
long long dp[10005][105];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, k, x;
    cin >> t;
    for(int k = 1; k <= 100; k++)
    {
    	dp[1][k] = 1;
    	for(int i = 2; i <= 10000; i++)
    	{
	        if(i <= k)
    	        dp[i][k] = 1;
        	else
            	dp[i][k] = 0;
        	for(int j = i - 1; j >= max(1, i - k); j--)
        	    dp[i][k] = (dp[i][k] + dp[j][k]) % 1000000007;
        }
    }
    while(t--)
    {
        cin >> x >> k;
        cout << dp[x][k] << endl;
    }
}
