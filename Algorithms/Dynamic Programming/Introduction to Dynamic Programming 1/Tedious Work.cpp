#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, n, k;
	cin >> n >> k;
	vector<int> v(n), c(n);
    for(i = 0; i < n; i++)
		cin >> v[i];
	for(i = 0; i < n; i++)
		cin >> c[i];
	vector<int> dp(n + 1, 0);
	dp[n - 1] = min(v[n - 1], c[n - 1]);
	for(i = n - 2; i >= 0; i--)
    {
		int mi = dp[i + 1] + v[i], x = c[i];
		for(j = i + 1; j < min(i + k + 1, n + 1); j++)
			mi = min(mi, x + dp[j]);
    	dp[i]=mi;
	}
	cout << dp[0] << endl;
	return 0;
}
