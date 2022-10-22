#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	unordered_set<long long> s;
	for(int i = 0; i < n; i++)
	{
		long long sum = 0, max_sum = INT_MIN;
		for(int j = i ; j<n ; j++)
		{
			sum += a[j];
			max_sum = max(sum, max_sum);
			if(sum < 0)
				sum = 0;
			s.insert(max_sum);
		}
	}
	long long ans = 0;
	for(auto i : s)
		ans += i;
	cout << ans;
}
