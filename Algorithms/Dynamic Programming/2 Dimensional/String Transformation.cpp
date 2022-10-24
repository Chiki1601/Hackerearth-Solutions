#include<bits/stdc++.h>
using namespace std;

int main()
{
    int TestCases = 1;
    cin >> TestCases;
    while(TestCases--)
    {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        swap(s, t);
        swap(n, m);
        int dp[n + 1][m + 1];   
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int j = 1; j <= n; j++)
            if(s[j - 1] >= 'a' && s[j - 1] <= 'z')
	            break;  
            else
	            dp[j][0] = 1;
        for(int i = 1; i <= n; i++)
        {
	        for(int j = 1; j <= m; j++)
	        {
 		        if(s[i - 1] >= 'a' && s[i - 1] <= 'z')
		        {
			        if(s[i - 1] == t[j - 1])
				        dp[i][j] = dp[i - 1][j - 1];
			        else
				        dp[i][j] = 0;
		        }
		        else
		        {
			        int length = s[i - 1] - '0';
				    dp[i][j] = 0;
				    for(int d = 0; d <= min(length, j); d++)
					    dp[i][j] |= dp[i - 1][j - d];		
		        }
	        }
        }
        if(dp[n][m])
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
}
