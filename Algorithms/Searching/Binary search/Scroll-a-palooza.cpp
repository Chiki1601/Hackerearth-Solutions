#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long tc; 
	cin >> tc; 
	while(tc--) 
	{
		long long n, m;
		cin >> n;
		vector<long long> x(n), a(n), b(n);
		for(auto &inVar : x) 
			cin >> inVar;
		for(auto i = 1; i < n; i++)
			x[i] += x[i - 1];
		for(auto i = 0; i < n; i++)
			x[i] = abs(x[i]);
		a[0] = x[0];
		b[n - 1] = x[n - 1];
		for(auto i = 1; i < n; i++)
			a[i] = max(a[i - 1], x[i]);
		for(long long i = n - 2; i >= 0; i--) 
			b[i] = max(b[i + 1], x[i]);
		reverse(b.begin(), b.end());
		cin >> m;
		while(m--) 
		{
			long long w = 0;
			cin >> w;
			long long i = lower_bound(a.begin(), a.end(), w) - a.begin() + 1, j = n - (lower_bound(b.begin(), b.end(), w) - b.begin());
			if(i == n + 1) 
				cout << -1 << "\n";
			else 
				cout << i << " " << j << "\n";
		}
	}
}
