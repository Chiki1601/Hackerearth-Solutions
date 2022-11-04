#include <bits/stdc++.h>
using namespace std;   
 
int main() 
{     
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    int t = 1, dp[2055][33][26], arr[2055], n, K;
    string s;
    while(t--)
    {
        cin >> s >> K;
        n = s.length(); 
        for(int i = 0; i < n; i++)
            arr[i + 1] = s[i] - 'a';
        for(int i = 0; i <= n; i++)
            for(int j = 0; j < 33; j++)
                for(int k = 0; k < 26; k++)
                    dp[i][j][k] = 1000000;
        for(int i = 0; i < 26; i++)
            dp[1][0][i] = (i - arr[1] + 26) % 26;
        for(int i = 2; i < n + 1; i++)
            for(int j = 0; j <= K; j++)
            {
                int mn = 10000000;
                if(j > 0) 
                    for(int k = 0; k < 26; k++)
                        mn = min(mn, dp[i - 1][j - 1][k]);
                for(int k = 0; k < 26; k++) 
            		dp[i][j][k] = min(mn, dp[i - 1][j][k]) + ((k - arr[i] + 26) % 26);
            } 
        int ans = 10000000;
        for(int i = 0; i <= K; i++)
            for(int j = 0; j < 26; j++)
                ans = min(ans, dp[n][i][j]);
        cout << ans;
    }
}
