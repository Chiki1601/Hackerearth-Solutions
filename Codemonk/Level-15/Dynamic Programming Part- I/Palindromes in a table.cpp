#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, Dp[2][501][501];
    cin >> n;
    char c[501][501];
    for(int i = 0; i < n; i++)
    {  
        cin >> c[i]; 
        Dp[0][i][i] = 1;
    }
    for(int k = 1; k < n; k++)
    {
	    auto old = Dp[!(k & 1)], dp = Dp[k & 1];
	    for(int i = 0; i < n - k; i++)
	        for(int j = 0; j < n - k; j++)
		        if(c[n - k - i - 1][i] == c[n - j - 1][j + k])
		            dp[i][j] = ((old[i][j] + old[i + 1][j]) % 1000000007 + (old[i][j + 1] + old[i + 1][j + 1]) % 1000000007) % 1000000007;
		else
		    dp[i][j] = 0;
    }
    cout << Dp[!(n & 1)][0][0] << endl;
    return 0;
}
