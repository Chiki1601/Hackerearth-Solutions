#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, m; 
	cin >> n >> m;
    vector<vector<long long int>> edges(m, vector<long long int> (3));
    for(long long int i = 0; i < m; i++)
	{
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--; 
		edges[i][2]--;
    }
    vector<long long int> ans(n, 1000000000000000000);
    ans[0] = 0;
    for(long long int i = 1; i <= n; i++)
	{
        vector<long long int>dp(n, 1000000000000000000);
        for(auto &x : edges)
		{
            dp[x[2]] = min(dp[x[2]], ans[x[1]] + i * x[0]);
            dp[x[1]] = min(dp[x[1]], ans[x[2]] + i * x[0]);
        }
        for(long long int k = 0; k < n; k++)
            ans[k] = min(ans[k], dp[k]);
    }
    for(long long int i = 0; i < n; i++)
	{
        if(ans[i] == 1000000000000000000)
            ans[i] = -1;
        cout << ans[i] << "\n";
    }
    return 0;
}
