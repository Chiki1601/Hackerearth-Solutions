#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test = 1;
	cin >> test;
	while(test--) 
	{
		int n, q; 
		cin >> n;
		vector<vector<int>> dp(n + 1, vector<int> (2, 0));
		for(int i = 1; i <= n; ++i) 
		{
			int x; 
			cin >> x;
			if(x <= 1) 
				++dp[i][x];
			for(int j = 0; j < 2; ++j) 
				dp[i][j] += dp[i - 1][j];
		}
		cin >> q;
		while(q--) 
		{
			int l, r; 
			cin >> l >> r;
			long long ans = 1LL * (r - l) * (r - l + 1) / 2;
			int one = dp[r][1] - dp[l - 1][1], zero = dp[r][0] - dp[l - 1][0];
			ans -= 1LL * one * zero;
			ans -= 1LL * zero * (zero - 1) / 2;
			cout << ans << "\n";
		}
	}
	return 0;
}
