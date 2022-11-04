#include<bits/stdc++.h>
using namespace std;
long long n, k, dp[201][201];
 
long long f(int i, int j)
{
	if(i != 0 && j > n) 
		return 0;
	if(i == 0) 
		return 1;
	if(dp[i][j] != -1) 
		return dp[i][j];
	long long ans = 0;
	if(i - j >= 0)
		ans += f(i - j, j);
	ans += f(i, j + 1);
	return dp[i][j] = ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		memset(dp, -1, sizeof(dp));
		cout << f(n, k) << endl;
	}
	return 0;
}
