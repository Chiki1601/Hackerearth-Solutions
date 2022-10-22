#include <bits/stdc++.h>
using namespace std;
 
long long get(long long x)
{
    return (x / 2) * (x / 2 + 1) - (x % 2 == 0) * (x / 2);
}
 
long long rng(long long l, long long r) 
{
    long long nums = r - l + 1;
    return nums * (l + r) / 2;
}
 
long long sol(long long n, long long i) 
{
    if(i <= n / 2)
        return get(i);
	i = min(i, 2 * n / 3);
    return get(n / 2) + (n + 1) * (i - (n / 2)) - rng(1 + n / 2, i) - get(i + 1) + get(1 + n / 2);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t;
	cin >> t;
	while(t--)
	{
		long long n, k;
		cin >> n >> k;
		assert(0 <= k && k <= n);
		assert(n <= 1000000000);
		long long val = (n * n + 6) / 12, lo = max(2LL, (n - k + 1) / 2), hi = min(n - 1, (n + k) / 2);
		if(lo > hi)
			cout << val << '\n';
		else
			cout << val - sol(n, hi) + sol(n, lo - 1) << '\n';
	}
}
