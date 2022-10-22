#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n;
	long long k, a[200000];
	cin >> t;
	while(t--) 
	{
		cin >> n >> k;
		multiset<long long> s;
		for(int i = 0; i < n; ++i) 
		{
			long long x;
			cin >> a[i];
		}
		long long ans = 0;
		for(int i = 61; i >= 0; --i) 
		{
			long long mn = LLONG_MAX;
			int id;
			for(int j = 0; j < n; ++j)
				if(a[j] >> i & 1)
				{
					mn = 0; 
					id = j;
				}
				else if(mn >= (1ll << i) - (a[j] & (1ll << i) - 1))
				{
					mn = (1ll << i) - (a[j] & (1ll << i) - 1); 
					id = j;
				}
			if(mn <= k) 
			{
				k -= mn;
				a[id] += mn;
				ans |= 1ll << i;
			}
		}
		cout << ans << endl;
	}
}
