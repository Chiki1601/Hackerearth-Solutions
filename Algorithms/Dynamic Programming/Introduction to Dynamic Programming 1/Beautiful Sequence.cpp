#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t; 
	cin >> t;
	while(t--)	
	{
		long long n; 
		cin >> n;
		long long a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		vector<long long>v(n, 2000000001);	
		long long maxx = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i] - i >= 0)
			{
				long long x = a[i] - i;
				long long idx = upper_bound(v.begin(), v.end(), x) - v.begin();
				v[idx] = x;
				maxx = max(maxx, idx + 1);
			}
		}
		cout << n - maxx << endl;
	}
	return 0;
}
