#include <bits/stdc++.h>
using namespace std;
int n, k, dp[10017];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	dp[0] = 1;
	for(int i = 1; i < n; i++)
		for(int j = max(0, i - k); j < i; j++)
			(dp[i] += dp[j]) %= 1000000007;
	cout << dp[n - 1] << "\n";
}
