#include<bits/stdc++.h>
using namespace std;
int n, m, A[2100][10031], B[2100][10031], pr[20000];
 
int main()
{
    long long dp[3][10031], best_res[10031], S[21], p[3], q[3], r[3], s[3];
	for(int i = 2; i < 10031; i++)
	{
		if(pr[i] == 0)
		{
			for(int j = i; j < 10031; j += i)
			    if(pr[j] == 0)
				    pr[j] = i;
		}
	}
	cin >> n >> m;
	cin >> s[0] >> p[0] >> q[0] >> r[0];
	cin >> s[1] >> p[1] >> q[1] >> r[1];
	long long ts = s[0];
	for(int i = 0; i < (n*m); i++)
	{
		long long nts = (p[0] * ts % 1000000003 * ts + q[0] * ts + r[0]) % 1000000003;
		A[(i / m) + 1][(i%m) + 1] = nts;
		ts = nts;
	}
	S[0] = s[1];
	p[0] = p[1];
	q[0] = q[1];
	r[0] = r[1];
	ts = S[0];
	for(int i = 0; i < (n*m); i++) 
	{
		long long nts = (p[0] * ts % 1000000003 * ts + q[0] * ts + r[0]) % 1000000003;
		B[(i / m) + 1][(i%m) + 1] = nts;
		ts = nts;
	}
	for(int i = 1; i <= m; i++)
		dp[1][i] = 0;
	for(int i = 2; i <= n; i++)
	{
		for(int val = 2; val <= 10031; val++)
			best_res[val] = 1e15;
		for(int j = 1; j <= m; j++)
			dp[i % 2][j] = 1e15;
		for(int j = 1; j <= m; j++)
		{
			if(pr[j] >= 1 && pr[j] <= 10031)
			{
				dp[i % 2][j] = min(dp[i % 2][j], best_res[pr[j]]);
				best_res[pr[j]] = min(best_res[pr[j]], dp[1 - i % 2][j] + B[i - 1][j]);
			}
		}
		for(int val = 2; val <= 10031; val++)
			best_res[val] = 1000000000000000;
		for(int j = m; j >= 1; j--)
		{
			if(pr[j] >= 1 && pr[j] <= 10031)
			{
				dp[i % 2][j] = min(dp[i % 2][j], best_res[pr[j]]);
				best_res[pr[j]] = min(best_res[pr[j]], dp[1 - i % 2][j] + B[i - 1][j]);
			}
		}
		for(int j = 1; j <= m; j++)
			dp[i % 2][j] = min(dp[i % 2][j], dp[1 - i % 2][j] + A[i - 1][j]);
		for(int j = 2; j <= m; j++)
			dp[i % 2][1] = min(dp[i % 2][1], dp[1 - i % 2][j] + B[i - 1][j]);
	}
	long long ans = 1000000000000000;
	for(int i = 1; i <= m; i++)
		ans = min(ans, dp[n % 2][i]);
	cout << ans << endl;
	cin.get(); 
    cin.get();
	return 0;
}
