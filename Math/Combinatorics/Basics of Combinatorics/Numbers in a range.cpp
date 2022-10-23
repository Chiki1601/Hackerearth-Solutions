#include<bits/stdc++.h>
using namespace std;
 
long long modexp(long long x, long long n)
{
    if(n == 0)
        return 1;
    if(n == 1)
		return x % 1000000007;
    long long y = modexp(x, n / 2);
    if(n % 2 == 0)
		return (y * y) % 1000000007;
    else
		return (((y * y) % 1000000007) * x) % 1000000007;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long l, r, n, i;
	cin >> l >> r >> n;
	long long a[n];
	for(i = 1; i < n; ++i)
		cin >> a[i];
	long long B = r - l + 1 - n;
	for(i = 1; i < n; ++i)
		B -= max(0ll, a[i] - 1);
	if(B < 0)
	{
		cout << 0;
		return 0;
	}
	long long ans = 1;
	for(i = 1; i <= B; ++i)
	{
		ans = (ans * (n + i)) % 1000000007;
		ans = (ans * modexp(i, 1000000005)) % 1000000007;
	}
	cout << ans;
	return 0;
}
