#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		long long n, k;
		cin >> n >> k;
		if(n < k) 
		{
			cout << n + 1 << endl;
			continue;
		}
		long long ans = k;
		long long num = n - ans + 1, mul = (k - 1) * k, i = 2;
		for(i = 2; num >= mul; i++)
		{
			ans += mul * i;
			num -= mul;
			mul *= k;
		}
		ans += num * i;
		cout << ans << endl;
	}
}
