#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, k, t, m, n, p;
	cin >> n;
	int l[n], r[n], dp[n], maxL = -1;
	for(i = 0; i < n; ++i) 
		cin >> l[i];
	for(i = 0; i < n; ++i) 
		cin >> r[i];
    vector<pair<int, int>> intervals(n);
	for(i = 0; i < n; ++i) 
		intervals[i] = {r[i], l[i]};
	sort(intervals.begin(), intervals.end());
	dp[0] = 1;
	for(i = 1; i < n; ++i) 
    {
		j = lower_bound(intervals.begin(), intervals.end(), make_pair(intervals[i].second, 0)) - intervals.begin();
		j--;
		if(j == -1) 
        {
			dp[i] = 1;
			continue;
		}
		dp[i] = 0;
		int maxL = -1;
		while(j >= 0 && intervals[j].first > maxL) 
        {
			dp[i] = (dp[i] + dp[j]) % 1000000007;
			maxL = max(maxL, intervals[j].second);
			--j;
		}
	}
	j = n - 1;
	long long ans = 0;
	while(j >= 0 && intervals[j].first > maxL) 
    {
		ans = (ans + (dp[j] * 1LL * intervals[j].first) % 1000000007) % 1000000007; 
		maxL = max(maxL, intervals[j].second);
		--j;
	}
	cout << ans;
}
