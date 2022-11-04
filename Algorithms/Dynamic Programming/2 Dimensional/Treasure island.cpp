#include<bits/stdc++.h>
using namespace std;
int dpsum[55][55], a[55][55], dp[52][52][52][52], n, m;
 
int getsum(int str, int stc, int enr, int enc)
{
    int val = dpsum[enr][enc] - dpsum[enr][stc - 1] - dpsum[str - 1][enc] + dpsum[str - 1][stc - 1];
    return val;
}
 
int solve(int strx, int stcx, int enrx, int encx)
{
    if(enrx == strx && stcx == encx)
        return 0;
    else if(dp[strx][stcx][enrx][encx] != -1)
        return dp[strx][stcx][enrx][encx];
    else
    {
        int val1 = getsum(strx, stcx, enrx, encx), val = 10000000000;
        for(int i = strx; i < enrx; i++)
            val = min(val, val1 + solve(i + 1, stcx, enrx, encx) + solve(strx, stcx, i, encx));
        for(int i = stcx; i < encx; i++)
            val = min(val, val1 + solve(strx, i + 1, enrx, encx) + solve(strx, stcx, enrx, i));
        return dp[strx][stcx][enrx][encx] = val;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof dp);
    int i, j, k;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            dpsum[i][j] = a[i][j] + dpsum[i][j - 1];
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            dpsum[i][j] += dpsum[i - 1][j];
    }
    cout << solve(1, 1, n, m) << endl;
    return 0;
}
