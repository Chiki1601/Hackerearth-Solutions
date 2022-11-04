#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string>v(n);
    for(int h = 0; h < n; h++)
        cin >> v[h];
    if(v[n - 1][m - 1] == '1' or v[0][0] == '1')
    {
        cout << 0 << endl;
        exit(0);
    }
    vector<vector<long long>>dp(n, vector<long long>(m, 0));
    dp[n - 1][m - 1] = 1;
    vector<int>cc(m, -1), rr(n, -1);
    for(int h = n - 1; h >= 0; h--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            if(v[h][j] == '1') 
                continue;
            if(cc[j] != -1)
                dp[h][j] = (dp[h][j] % 1000000007 + dp[cc[j]][j] % 1000000007) % 1000000007;
            if(rr[h]!=-1)
                dp[h][j] = (dp[h][j] % 1000000007 + dp[h][rr[h]] % 1000000007) % 1000000007;
            cc[j] = h;
            rr[h] = j;
        }
    }
    cout << dp[0][0] << endl;
}
