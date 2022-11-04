#include <bits/stdc++.h>
using namespace std; 
int n, m, ind[5010], dp[5010][5010];      
 
int main() 
{
	string s; 
    cin >> n >> s;
    if(s[0] == '0')
        return cout << 0 << endl, 0;
    for(int i = 0; i < n; i++) 
	{
        if(s[i] == '1') 
            ind[m++] = i;
    }
    for(int i = m - 1; i >= 0; i--) 
	{
        for(int j = n; j >= 1; j--) 
		{
            if(i + j > m) 
			continue;
            if(i + j == m) 
			{
                dp[i][j] = 1;
                continue;
            }
            int len = ind[i + j] - ind[i];
            if(ind[i + j] + len > n) 
			{
                dp[i][j] = dp[i][j + 1];
                continue;
            }
            int k = lower_bound(ind, ind + m, ind[i + j] + len) - ind;
            int p = max(j, k - (i + j));
            dp[i][j] = (dp[i][j + 1] + dp[i + j][p]) % 1000000007;
        }
    }
    cout << dp[0][1] << endl;
    return 0;
}
