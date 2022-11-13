#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, x[2][1000014];
	cin >> t;
	while (t--) 
	{
		cin >> n;
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			cin >> x[0][i] >> x[1][i];
		for (auto &c : x) 
		{
			sort(c, c + n);
			for (int i = 0; i < n; ++i)
				ans += c[i] * (ll) i - c[i] * ll(n - i - 1);
		}
		cout << ans << endl;
	}
}
