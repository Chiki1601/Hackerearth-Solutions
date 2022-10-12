#include <bits/stdc++.h>
using namespace std;
int a[16], b[16];
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) 
    {
		int n, ans = INT_MAX;
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		for(int mask = 0; mask < 1 << n; ++mask) 
        {
			vector<int> v[2];
			for(int i = 0; i < n; ++i)
				v[(i + (mask >> i & 1)) % 2].push_back(i);
			if(v[1].size() != n / 2)
				continue;
			auto cmp = [&mask](int i, int j) 
            {
				return (mask >> i & 1 ? b[i] : a[i]) < (mask >> j & 1 ? b[j] : a[j]);
			};
			for(auto &vec : v)
				stable_sort(vec.begin(), vec.end(), cmp);
			vector<int> all(n);
			for(int i = 0; i < n; ++i)
				all[i] = v[i % 2][i / 2];
			if(is_sorted(all.begin(), all.end(), cmp)) 
            {
				int cur = 0;
				for(int i = 0; i < n; ++i)
					for(int j = 0; j < i; ++j)
						cur += all[i] < all[j];
				ans = min(ans, cur);
			}
		}
		cout << (ans == INT_MAX ? -1 : ans) << endl;
	}
}
