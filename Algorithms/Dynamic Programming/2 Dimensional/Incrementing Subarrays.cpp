#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int z;
	for(scanf("%d", &z); z; --z) 
    {
		int n, m, last;
		cin >> n >> m >> last;
		vector<long long> dp(3);
		for(--n; n; --n) 
        {
			int x;
			cin >> x;
			dp = {dp[0] + x % last, max(dp[0] + (x + m) % last, dp[1] + (x + m) % (last + m)), max(dp[2] + x % last, dp[1] + x % (last + m))};
			last = x;
		}
		cout << max(dp[0], max(dp[1], dp[2])) << endl;
	}
	return 0;
}
