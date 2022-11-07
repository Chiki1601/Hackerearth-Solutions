#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t; 
	cin >> t;
	while(t--)
	{
		long long n; 
		cin >> n;
		vector<pair<long long, long long>>v(n);
		for(int i = 0; i < n; i++)
		{
			cin >> v[i].first;
			cin >> v[i].second;
		}
		sort(v.rbegin(), v.rend());
		long long ans = v[0].second, dp[n];
		dp[0] = v[0].second;
		for(int i = 1; i < n; i++)
		{
			long long temp, count = LONG_LONG_MIN;
			for(int j = 0; j < i; j++)
			{
				if(v[i].second < v[j].second && v[i].first < v[j].first)
					temp = v[i].second + dp[j];
				else 
					temp = v[i].second;
				count = max(count, temp);
			}
			dp[i] = count;
			ans = max(dp[i], ans);
		}
		cout << max(ans, (long long)0) << endl;
	}
	return 0;
}
