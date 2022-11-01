#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, x;
	cin >> n >> x;
	long long a[n];
	for(long long i = 0; i < n; i++)
		cin >> a[i];
	long long i = 1, j = n;
	while(i <= j)
	{
		long long k = (i + j) / 2, sum = 0;
		for(long long p = 0; p < k; p++)
			sum += a[p];		
		long long s = sum;
		for(long long p = 1; p < (n - k + 1); p++)
		{
			sum = (sum - a[p - 1]) + a[p + k - 1];
			s = max(s, sum);
		}
		if(s > x)
			j = k - 1;
		else
			i = k + 1;
	}
	cout << j << "\n";
}
