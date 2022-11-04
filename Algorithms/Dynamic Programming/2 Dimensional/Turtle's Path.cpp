#include<bits/stdc++.h>
using namespace std;
int prime[100007], a[1005][1005], mark[1005][1005], q = 0, n, m;
pair<int, int>ans[100005];
 
void dfs(int i, int j, int k)
{
    if(a[i][j] == 0 || i > n || j > m || mark[i][j] || q)
        return;
    mark[i][j] = 1;
    ans[k] = make_pair(i, j);
    if(i == n && j == m)
    {
        q = k;
        return;
    }
    dfs(i + 1, j + 1, k + 1);
    dfs(i + 1, j, k + 1);
    dfs(i, j + 1, k + 1);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 2; i * i <= 100005; i++)
    {
        if(prime[i] == 0)
        {
            for(int j = i * i; j <= 100005; j += i)
                prime[j] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(prime[a[i][j]] == 0)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
	long long dp[1005][1005];
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1)
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007;
            if(a[i][j] == 0)
                dp[i][j] = 0;
        }
    }
    cout << dp[n][m] << endl;
    dfs(1, 1, 1);
    for(int i = 1; i <= q; i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
