#include<bits/stdc++.h>
using namespace std;
 
long long power(long long a, long long b, long long mod)
{
    long long ret = 1;
    while(b)
	{
        if(b & 1) 
			ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1 ;
    }
    return ret;
}
 
int main()
{
	long long t, f[100100], invf[100100], i, j, k;
	f[0] = 1;
	invf[0] = power(f[0], 1000000005, 1000000007);
	for(i = 1; i <= 100000; i++)
	{
		f[i] = (f[i - 1] * i) % 1000000007;
		invf[i] = power(f[i], 1000000005, 1000000007);
	}
	cin >> t;
	while(t--)
	{
		long long n, k, ncr[100100], total = 0;
		cin >> n >> k;		
		if(k > n)
		{
			cout << 1 << endl;
			continue;	
		}
		for(int i = 1; i <= k; i++)
			ncr[i] = (f[n] * ((invf[i] * invf[n - i]) % 1000000007)) % 1000000007;
		for(int i = 1; i <= k; i++)
		{
			long long temp = (f[k - 1] * ((invf[i - 1] * invf[k - i]) % 1000000007) )% 1000000007;
			total = (total + ((ncr[i] * temp) % 1000000007)) % 1000000007;
		}					
		long long num = (total - ncr[k] + 1000000007) % 1000000007;		
		cout << (num * power(total, 1000000005, 1000000007)) % 1000000007 << endl;
	}	
	return 0;
}
