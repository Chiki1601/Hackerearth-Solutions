#include <bits/stdc++.h>
using namespace std;
int n, k, MOD, d[250001], hi[250001], f[250001], rf[250001];
 
int binPow(long long x, int p) 
{
    long long res = 1;
    while(p) 
	{
        if(p & 1) 
			res = res * x % MOD;
        p >>= 1;
        if(p) 
			x = x * x % MOD;
    }
    return (int)res;
}
 
int c(int n, int k) 
{
    return (long long)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i <= 250000; ++i) 
	{
        hi[i] = 1;
        while ((hi[i] * 2) <= i) 
            hi[i] *= 2;
    }
    cin >> n >> k >> MOD;
    f[0] = rf[0] = 1;
    for(int i = 1; i <= 250000; ++i) 
	{
        f[i] = (long long)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    int ans = 1;
    for(int i = 0; i < n; ++i)
		ans = (long long)ans * k % MOD;
    if(n % 2 == 1) 
	{
        cout << ans << endl;
        return 0;
    }
    d[n] = 1;
    while(k) 
	{
        d[0] = 0;
        for(int i = 1; i <= n; ++i) 
			if(d[i]) 
			{
            	for(int j = i; j >= hi[i]; j = ((j - 1) & i)) 
                	d[i ^ j] = (d[i ^ j] + (long long)k * c(i, j) % MOD * d[i]) % MOD;
            	d[i] = 0;
        	}
        ans -= d[0];
        if(ans < 0) 
			ans += MOD;
        --k;
    }
    cout << ans << endl;
    return 0;
}
