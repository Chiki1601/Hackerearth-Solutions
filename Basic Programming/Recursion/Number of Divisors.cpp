#include <bits/stdc++.h>
using namespace std;
 
long long rans(long long n,long long k)
{
	long long sum = n * (n + 1) / 2;
	if (n < 1)
		return sum;
	long long x = n / k;
	sum -= k * x * (x + 1) / 2;
	return sum + rans(x, k);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		long long n, k; 
		cin >> n >> k;
		cout << rans(n, k) << endl;
	}
	return 0;
}
