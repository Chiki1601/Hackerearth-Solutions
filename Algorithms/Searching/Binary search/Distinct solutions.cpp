#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) 
	{
		int n, t1, t2;
		cin >> n >> t1 >> t2;
		long long lo = 0, hi = 1100000000000000000;
		while(hi - lo > 1) 
		{
			long long mid = (lo + hi) / 2;
			(mid / t1 + mid / t2 < n ? lo : hi) = mid;
		}
		long long ans = hi;
		cout << (ans + t1 - 1) / t1 + (ans + t2 - 1) / t2 << ' ';
		if(ans % t1)
			ans = (ans + t1 - 1) / t1 * t1;
		else
			ans = (ans + t2 - 1) / t2 * t2;
		cout << ans << endl;
	}
}
