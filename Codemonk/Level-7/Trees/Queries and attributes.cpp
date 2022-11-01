#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a[100014], l[100014], r[100014], q;
	long long b[100014];
	multiset<long long> s;
	vector<long long> add[100014], rem[100014];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i]; 
		l[i]--; 
		r[i]--;
	}
	for(int i = n - 1; i >= 0; i--)
	{
		for(auto x : add[i])
			s.insert(x);
		if(i != n - 1)
			b[i] = s.size() ? *s.begin() : 1000000000000000000;
		if(i)
		{
			add[r[i]].push_back(b[i] + a[i]);
			rem[l[i]].push_back(b[i] + a[i]);
		}
		for(auto x : rem[i])
			s.erase(s.find(x));
	}
	for(int i = 1; i < n; i++)
		b[i] = min(b[i - 1], b[i]);
	cin >> q;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		cout << b[x - 1] + y << "\n";
	}
}
