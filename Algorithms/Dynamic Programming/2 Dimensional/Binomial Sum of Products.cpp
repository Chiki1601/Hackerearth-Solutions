#include <bits/stdc++.h>
using namespace std;
long long f[1005], inf[1005], dp[1005][1005];
 
long long inv(long long a)
{
	long long ans = 1, n = 1000000005;
	while(n)
	{
		if(n & 1)
			ans = (ans * a) % 1000000007;
		n>>=1;
		a = (a * a) % 1000000007;
	}
	return ans;
}
 
long long ncr(long long n, long long r)
{
	if(n < r)
		return (n * r) % 1000000007;
	return ((f[n] * inf[r] % 1000000007) * inf[n - r]) % 1000000007;
}
 
int main() 
{
	long long t, i, j, a, b, c, d;	
	f[0] = 1;
	for(i = 1; i < 1005; i++)
		f[i] = (f[i - 1] * i) % 1000000007;	
	for(i = 0; i < 1005; i++)
		inf[i] = inv(f[i]);
	for(i = 0; i < 1005; i++)
	{
		dp[i][0] = 1;
		for(j = 0; j < 1005; j++)
			dp[i][j + 1] = (dp[i][j] * ncr(i, j)) % 1000000007;
	}
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c >> d;
		long long ans = 0;
		for(i = a; i <= b; i++)
			ans = (ans + dp[i][d + 1] * inv(dp[i][c])) % 1000000007;
		cout << ans << endl;
	}
}
