#include <bits/stdc++.h> 
using namespace std;
 
int main() 
{
	int t, n;
	cin >> t;
	assert(t >= 1 && t <= 100);
	for(int i = 0; i < t; i++) 
	{
		cin >> n;
		assert(t >= 1 && t <= 100);
		vector<int> a(2);
		for(int j = 0; j < n; j++) 
		{
			int k;
			cin >> k;
			assert(k >= 1 && k <= 100);
			a[k % 2]++;
		}
		if(a[0] == 0 || a[0] == n || abs(a[0] - a[1]) <= 1) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}
