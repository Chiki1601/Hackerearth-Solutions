#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, x, a[201000] = {0}, f[201000] = {0}, t;
	cin >> n;
    for(long long i = 0; i < n; i++)
    {
        cin >> x;
        f[x]++;
    }
	for(long long i = 1; i <= 200000; i++)
		for(long long j = i; j <= 200000; j += i)
			a[i] += f[j];
	cin >> t;
	while(t--)
	{
		long long p, q;
		cin >> p >> q;
		long long temp = lcm(p, q);
		if(temp > 200000)
		 	cout << a[p] + a[q] << "\n";
		else
		    cout << a[p] + a[q] - a[temp] << "\n";
	}
	return 0;
}
