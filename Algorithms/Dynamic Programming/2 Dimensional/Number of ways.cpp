#include<bits/stdc++.h>
using namespace std;
long long n, m, dp[1002][1002], rsum[1002][1002], csum[1002][1002];
string mat[1001];
 
void solution()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> mat[i];
    if(mat[0][0] == '*' || mat[n - 1][m - 1] == '*')
    {
        cout << "0" << endl;
        return;
    }
    dp[1][1] = rsum[1][1] = csum[1][1] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(i == 1 && j == 1)
                continue;
            if(mat[i - 1][j - 1] == '*')
            {
                dp[i][j] = rsum[i][j] = csum[i][j] = 0;
                continue;
            }
            dp[i][j] = (csum[i][j - 1] + rsum[i - 1][j]) % 1000000007;
            csum[i][j] = (dp[i][j] + csum[i][j - 1]) % 1000000007;
            rsum[i][j] = (dp[i][j] + rsum[i - 1][j]) % 1000000007;
        }
    }
    cout << dp[n][m] << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(12);
    int t;
    cin >> t;
    while(t--)
        solution();
    return 0;
}
