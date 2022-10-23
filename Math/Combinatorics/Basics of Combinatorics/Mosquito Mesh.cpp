#include<bits/stdc++.h>
using namespace std;
long long n, m, fact[200005], inv[200005];
 
long long f(long long a, long long b)
{
	long long ans = 1;
	while(b)
    {
		if(b & 1) 
            ans = (ans * a) % 1000000007;
		a = (a * a) % 1000000007;
		b>>=1;
	}
	return (ans + 1000000007) % 1000000007;
}
map<long long, int>h;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fact[0] = 1;
	inv[0] = 1;
	for(long long i = 1; i < 200005; ++i)
	{
		fact[i] = (i * fact[i - 1]) % 1000000007;
		inv[i] = f(fact[i], 1000000005);
	}
	cin >> n >> m;
	long long x, l;
	while(m--)
    {
		cin >> x >> l;
		for (int i = x + 1; i < x + l; ++i)
			h[i] = 1;
	}
	long long ans = 0;
	for (int i = 0; i <=n; ++i)
	{
		if(h.count(i) == 0)
        {
			long long x  = ((fact[n] * inv[n - i]) % 1000000007 * inv[i]) % 1000000007;
			x = (x * x) % 1000000007;
			ans = (ans + x) % 1000000007;
		}
	}
	cout << (ans + 1000000007) % 1000000007;
	return 0;
 
}
