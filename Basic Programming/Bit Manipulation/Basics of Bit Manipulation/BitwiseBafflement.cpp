#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) 
    {
		int n, sg = 0;
		cin >> n;
		vector<int> a(n), x(n + 1), s(n + 1);
		for(int i = 0; i < static_cast<int>(n); ++i)
			cin >> a[i];
		for(int i = 0; i < static_cast<int>(n); ++i)
        {
			sg ^= a[i];
			x[i + 1] = __builtin_popcount(sg) % 2;
			s[i + 1] = s[i] + x[i];
		}
		long long ret = 0;
		vector<pair<int, int>> b, c;
		c.push_back({0, 0});
		for(int p = 0; p < static_cast<int>(n); ++p)
        {
			int val = a[p], s0 = 0;
			b.clear();
			b.push_back({ val, p + 1 });
			for(const auto& t : c) 
            {
				int new_val = (val & t.first);
				if(new_val != val)
				{
					val = new_val;
					b.push_back({ val, t.second });
				}
			}
			c.swap(b);
			for(int i = 0; i < c.size(); ++i) 
            {
				if(__builtin_popcount(c[i].first) % 2 == 1) 
                {
					int j = (i + 1 < c.size() ? c[i + 1].second : 0), k = c[i].second;
					if(x[p + 1] == 0) 
						s0 += (k - j) - (s[k] - s[j]);
					else 
						s0 += s[k] - s[j];
				}
			}
			ret += s0;
		}
		cout << ret << "\n";
	}
	return 0;
}
