#include<bits/stdc++.h>
using namespace std;
 
long long totient(long long n)
{
    long long res = n;
    if(n % 2 == 0)
		res -= (res / 2);
    while(n % 2 == 0)
		n /= 2;
    for(long long i = 3 ; i * i <= n; i += 2)
	{
        if(n % i == 0)
			res -= (res / i);
        while(n % i == 0)
			n /= i;
    }
    if(n > 1)
		res -= res / n;
    return res;
}  
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)
    {
		long long n, ans = 1;
		cin >> n;
		for(long long i = 1 ; i * i <= n ; i++) 
		{
			if(n % i == 0) 
			{
				ans *= totient(i) % 1000000007;
				ans %= 1000000007;
				if(n/i!=i) 
				{
					ans *= totient(n / i) % 1000000007;
					ans %= 1000000007;
				}
			}
		}
		cout << ans << endl;
	} 
    return 0;
}
