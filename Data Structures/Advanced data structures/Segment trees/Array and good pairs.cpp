#include<bits/stdc++.h>
using namespace std;
int n, t, l, r, ch;
long long bit[64][100005] = {}, arr[100005], inv2;
 
void update(long long b[], int i, long long val) 
{
	for( ; i <= n; i += (i & -i)) 
		b[i] += val;
}
 
long long get(long long b[], int i) 
{
	long long res = 0;
	for( ; i; i -= (i & -i)) 
		res += b[i];
	return res;
}
 
void convert(int i, long long x, long long val) 
{
	int id = 0;
	for(int p2 = 1; x; x /= 10, p2 <<= 1) 
	{
		if(x % 10) 
			id += p2;
	}
	update(bit[id], i, val);
}
 
long long inv(long long a, long long b) 
{
	long long res = 1;
	for( ; b; b >>= 1 ) 
	{
		if(b & 1) 
			res = (res * a) % 1000000007;
		a = (a * a) % 1000000007;
	}
	return res;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	inv2 = inv(2LL, 1000000005);
	cin >> n;
	for(int i = 0; i < n; i++)
	{ 
		cin >> arr[i];
		convert(i + 1, arr[i], arr[i]);
	}
	cin >> t;
	while(t--) 
	{
		cin >> ch >> l >> r;
		if(!ch) 
		{
			convert(l, arr[l - 1], -arr[l - 1]);
			arr[l - 1] = r;
			convert(l, r, r);
			continue;
		}
		long long sm[64], smm[64], res = 0;
		for(int i = 0; i < 64; i++) 
			smm[i] = sm[i] = (get(bit[i], r) - get(bit[i], l - 1)) % 1000000007;
		int p2 = 1;
		for(int i = 0; i < 6; i++) 
		{
			for(int j = 0; j < 64; j++) 
			{
				if(j & p2) 
					sm[j] = (sm[j] + sm[j ^ p2]) % 1000000007;
			}
			p2 <<= 1;
		}
		for(int i = 0; i < 64; i++) 
			res = (res + (smm[i] * sm[63 - i]) % 1000000007) % 1000000007;
		res = (res * inv2) % 1000000007;
		cout << res << "\n";
	}
	return 0;
}
