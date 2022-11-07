#include<bits/stdc++.h>
using namespace std;
 
long long lis(long long n, long long a[])
{
	vector<long long>v;
	v.push_back(a[0]);
	for(int i = 1; i < n; i++)
	{
		if(a[i] > v.back())
			v.push_back(a[i]);
		else
		{
			long long index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[index] = a[i];
		}
	}
	return v.size();
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n; 
	cin >> n;
	long long a[n], b[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	long long ans1 = n - lis(n, a);
	reverse(a, a + n);
	long long ans2 = n - lis(n, a);
	cout << min(ans1, ans2) << endl;
	return 0;
}
