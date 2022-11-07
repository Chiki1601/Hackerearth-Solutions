#include<bits/stdc++.h>
using namespace std;
int a[6], b[6], dp[11][11][11][11][11][11], tot = 0;
 
int solve(int prev, int curr)
{
	if(curr == tot)
		return 1;
	int res = 0;
	if(dp[a[1]][a[2]][a[3]][a[4]][a[5]][prev] != -1)
		return dp[a[1]][a[2]][a[3]][a[4]][a[5]][prev];
	for(int i = 1; i < 6; ++i)
	{
		if(i == prev)
			continue;
			int mn= min(b[i],a[i]);
			for(int j = 1; j < mn + 1; ++j)
			{
				a[i] -= j;
				int b1 = (curr + j) % 1000000007;
				int a1 = solve(i, b1) % 1000000007;
				a[i] += j;
				res = (res + a1) % 1000000007;
			}
	}
	return dp[a[1]][a[2]][a[3]][a[4]][a[5]][prev] = res;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	tot = 0;
	for(int i = 1; i < 6; ++i)
	{
		cin >> a[i];
		tot += a[i];
	}
	for(int i = 1 ; i < 6; ++i)
		cin >> b[i];
	memset(dp, -1, sizeof(dp));
	int res = solve(0, 0);
	cout << res << endl;
}
