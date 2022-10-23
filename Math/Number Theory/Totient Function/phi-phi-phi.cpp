#include <bits/stdc++.h>
using namespace std;
map<long long, long long> prim;
 
long long gcd(long long a, long long b)
{ 
	return a ? gcd(b %a, a) : b; 
}
 
long long mulmod(long long a, long long b, long long c) 
{ 
	long long x = 0, y = a % c;
	while(b > 0)
	{
		if(b % 2 == 1) 
			x = (x + y) % c;
		y = (y * 2) % c;
		b /= 2;
	}
	return x % c;
}
 
long long expmod(long long b, long long e, long long m)
{
	if(!e) 
		return 1;
	long long q = expmod(b, e / 2, m); 
	q = mulmod(q, q, m);
	return e % 2 ? mulmod(b, q, m) : q;
}
 
bool es_primo_prob(long long n, int a)
{
	if(n == a) 
		return true;
	long long s = 0, d = n - 1;
	while (d % 2 == 0) 
	{	
		s++; 
		d /= 2;
	}
 	long long x = expmod(a, d, n);
	if((x == 1) || (x + 1 == n)) 
		return true;
 	for(int i = 0; i < s - 1; i++)
	{
		x = mulmod(x, x, n);
		if(x == 1) 
			return false;
		if(x + 1 == n) 
			return true;
	}
	return false;
}
 
bool rabin(long long n)
{
	if(n == 1)	
		return false;
	const int ar[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
	for(int j = 0; j < 9; j++)
		if(!es_primo_prob(n, ar[j]))
			return false;
	return true;
}
 
long long rho(long long n)
{
	if((n & 1) == 0) 
		return 2;
	long long x = 2, y = 2, d = 1, c = rand() % n + 1;
	while(d == 1)
	{
		x = (mulmod(x, x, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		if(x - y >= 0) 
			d = gcd(x - y, n);
		else 
			d = gcd(y - x, n);
	}
	return d == n ? rho(n) : d;
}
 
void factRho(long long n)
{ 	
	if(n == 1) 
		return;
	if(rabin(n))
	{
		prim[n]++;
		return;
	}
	long long factor = rho(n);
	factRho(factor);
	factRho(n / factor);
}
 
long long phi(long long n) 
{
	long long r = 1;
	prim.clear();
	factRho(n);
	for(auto P : prim) 
	{
		long long tmp1 = 1;
		for(int x = 0; x < P.second; x++) 
			tmp1 *= P.first;
		tmp1 /= P.first; tmp1 *= P.first - 1;
		r *= tmp1;
	}
	return r;
}
 
int main() 
{
	bool np[1000001] = {};
	vector<long long> primes;
	primes.push_back(2);
	for(int i = 3; i < 1000001; i += 2)
		if(!np[i]) 
		{
			primes.push_back(i);
			for(int j = i; j < 1000001; j += i) 
				np[j] = true;
		}
	long long N, K; 
	cin >> N >> K;
 	while (K && N > 1) 
	{
		K--;
		N = phi(N);
	}
	cout << N << endl;
}
