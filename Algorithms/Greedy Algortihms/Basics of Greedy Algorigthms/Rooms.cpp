#include <bits/stdc++.h> 
using namespace std;
void solve();
 
int main() 
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tc = 1;
	cin >> tc;
	while (tc--) 
        solve();
	return 0;
}
 
void solve() 
{
	int n;
	cin >> n;
	vector<pair<int, int>> times(2 * n);
	for (int i = 0; i < n; ++i) 
    {
		cin >> times[i].first;
		times[i].second = 1; // arrival
	}
	for (int i = 0; i < n; ++i) 
    {
		cin >> times[n + i].first;
		times[n + i].first += times[i].first;
		times[n + i].second = 0; // departure
	}
	sort(times.begin(), times.end());
	int ans = -1000000007, cnt = 0;
	for (auto [time, type] : times) 
    {
		if (type == 1) 
            ++cnt, ans = max(ans, cnt);
		else 
            --cnt;
	}
	cout << ans << endl;
}
