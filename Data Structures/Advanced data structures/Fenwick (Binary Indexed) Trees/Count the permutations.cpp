#include<bits/stdc++.h>
using namespace std;
int n, k, bit[200005] = {}, fre[200005] = {};
 
void update(int i, int val) 
{
	for( ; i < 200005; i += (i & -i)) 
		bit[i] += val;
}
 
int get(int i) 
{
	int res = 0;
	for( ; i; i -= (i & -i)) 
		res += bit[i];
	return res;
}
 
long long inv(long long a, long long b = 1000000005) 
{
	long long res = 1;
	for( ; b; b >>= 1) 
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
	long long den = 1, res = 0, fact[200005];
    fact[0] = 1;
	for(int i = 1; i < 200005; i++) 
		fact[i] = (fact[i - 1] * 1LL*i) % 1000000007;
	cin >> n;
	for(int i = 0; i < n; i++) 
    {
		cin >> k;
		fre[k]++;
		den = (den * fre[k]) % 1000000007;
		update(k, 1);
	}
	for(int i = 0; i < n; i++) 
    {
		cin >> k;
		int a = get(k - 1);
		res = (res + ((1LL * a * fact[n - i - 1]) % 1000000007 * inv(den)) % 1000000007) % 1000000007;
		if(!fre[k]) 
			break;
		update(k, -1);
		den = (den * inv(1LL * fre[k])) % 1000000007;
		fre[k]--;
	}
	cout << res;
	return 0;
}
