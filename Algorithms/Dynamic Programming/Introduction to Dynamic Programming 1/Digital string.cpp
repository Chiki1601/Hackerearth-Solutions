#include <bits/stdc++.h>
using namespace std;
int A[100005][4], vis[100005][10], dp[100005][10], tc, pre[] = {2, 4, 6, 8};
 
int f(int idx, int prev)
{
	if(idx == -1) 
		return 0;
	if(vis[idx][prev] == tc) 
		return dp[idx][prev];
	vis[idx][prev] = tc;
	int ans = 2000000000;
	for(int i = 0; i < 4; i++) 
	{
		if(pre[i] == prev) 
			continue;
		ans = min(ans, A[idx][i] + f(idx - 1, pre[i]));
	}
	dp[idx][prev] = ans;
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;
	for(tc = 1; tc <= t; tc++) 
	{
		cin >> n;
		for(int i = 0; i < n; i++) 
		{
			for(int j = 0; j < 4; j++) 
				cin >> A[i][j];
		}
		int ans = f(n - 1, 0);
		cout << ans << endl;
	}
	return 0;
}
