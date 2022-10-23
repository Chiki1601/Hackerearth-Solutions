#include <bits/stdc++.h>
using namespace std;
int p, fac[1000], facn, rt, ocr[1000009], pre[1000009];
 
template<class T>inline void read(T &x) 
{
  	char c;
	int f = 1;
	x = 0;
  	while(((c=getchar()) < '0' || c > '9') && c != '-');
  	if(c == '-') 
	  	f = -1;
	else 
		x = c - '0';
  	while((c = getchar()) >= '0' && c <= '9') 
	  	x = x * 10 + c - '0';
  	x *= f;
}
 
int fpm(int a, int b, int mod) 
{
	int ret = 1;
	while(b) 
	{
		if(b & 1) 
			ret = (long long)ret * a % mod;
		a = (long long)a * a % mod;
		b >>= 1;
	}
	return ret;
}
 
int gcd(int a, int b) 
{
	return b ? gcd(b, a % b) : a;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long L;
	bool valid[1000009];
	read(p), read(L);
	for(int d = 1; d * d < p; ++d) 
	{
		if((p - 1) % d == 0) 
		{
			fac[++facn] = d;
			if(d * d != p - 1) 
				fac[++facn] = (p - 1) / d;
		}
	}
	for(int i = 2; ; ++i) 
	{
		bool fl = true;
		for(int j = 2; j <= facn; ++j) 
		{
			if(fpm(i, (p - 1) / fac[j], p) == 1) 
			{
				fl = false;
				break;
			}
		}
		if(fl)
		{
			rt = i;
			break;
		}
	}
	for(int i = 1; i <= facn; ++i) 
	{
		int d = fac[i], base = fpm(rt, d, p);
		for(int k = 0, r_k = 1; k < p - 1; k += d, r_k = (long long)r_k * base % p)
		{
			ocr[r_k] = i;
			if(ocr[r_k - 1] == i or ocr[r_k + 1] == i) 
			{
				valid[d] = true;
				break;
			}
		}
		
	}
	for(int i = 1; i < p; ++i) 
		pre[i] = pre[i - 1] + valid[gcd(i, p - 1)];
	long long ans = 0;
	ans = L / (p - 1) * pre[p - 1];
	ans += pre[L % (p - 1)];
	cout << ans << endl;
	return 0;
}
