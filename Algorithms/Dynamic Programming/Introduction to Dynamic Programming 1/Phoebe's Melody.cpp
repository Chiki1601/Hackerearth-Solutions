#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t; 
	cin >> t;
	while(t--)
	{
		long long n, k; 
		cin >> n >> k;
		vector<pair<long long, long long>>v;
		for(int i = 1; i<=n; i++)
		{
			long long x; 
			cin >> x;
			v.push_back({x, i});
		}
		sort(v.begin(), v.end());
		set<long long>s;
		s.insert(v[0].second);
		long long ans = 0;
		for(int i = 1; i < n; i++)
		{
			long long temp = 100000000, bb = v[i].second - k, ff = v[i].second + k;
			set<long long>:: iterator left, right;
			left = s.lower_bound(bb);
			right = s.lower_bound(ff);
			bool flag = false;
			if(left == s.end() || *left > bb)
			{
				if(left == s.begin())
					flag = true;
                left--;
			}
			if(!flag && bb >= 1)
				temp = abs(v[i].second - *left);
			if(right != s.end() && ff <= n)
				temp = min(temp, abs(*right - v[i].second));
			if(temp != 100000000)
				ans += temp;
			s.insert(v[i].second);
		}
		cout << ans << endl;
	}
	return 0;
}
