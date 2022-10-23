#include <bits/stdc++.h>
using namespace std;
 
int fpm(int a, int b) 
{
	int r = 1;
	while(b) 
	{
		if(b & 1) 
			r = (long long)r * a % 167772161;
		a = (long long)a * a % 167772161, b >>= 1;
	}
	return r;
}
 
void NTT(vector<int> &a, int n, int f) 
{
	for(int i = 0; i < n; ++i) 
	{
		int s = i, p = 0;
		for(int j = 1; j < n; j <<= 1)
			p = p << 1 | (s & 1), s >>= 1;
		if(i < p) 
			swap(a[i], a[p]);
	}
	int v = fpm(3, (167772160) / n), w[530009];
	w[0] = 1;
	for(int i = 1; i <= n; ++i) 
		w[i] = (long long)w[i - 1] * v % 167772161;
	for(int l = 2; l <= n; l <<= 1) 
	{
		int t = n / l;
		for(int i = 0; i < n; i += l)
			for(int j = 0; j < (l >> 1); ++j) 
			{
				int wn = f == 1 ? w[t * j] : w[n - t * j];
				int x = a[i + j], y = (long long)a[i + j + (l >> 1)] * wn % 167772161;
				a[i + j] = (x + y) % 167772161, a[i + j + (l >> 1)] = (x - y + 167772161) % 167772161;
			}
	}
	if(f == -1) 
	{
		int inv = fpm(n, 167772159);
		for(int i = 0; i < n; ++i)
			a[i] = (long long)a[i] * inv % 167772161;
	}
}
 
vector<int> mult(vector<int> a, vector<int> b) 
{
	int l = (int)(a).size() + (int)(b).size() - 2, n = 1;
	while(n <= l) 
		n <<= 1;
	a.resize(n, 0), b.resize(n, 0);
	NTT(a, n, 1), NTT(b, n, 1);
	for(int i = 0; i < n; ++i) 
		a[i] = (long long)a[i] * b[i] % 167772161;
	NTT(a, n, -1), a.resize(l + 1);
	return a;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, fac[530009], S[59][59];
	vector<int> prd, bse;
	cin >> n >> k;
	fac[0] = 1;
	for(int i = 1; i <= n * k; ++i)
		fac[i] = (long long)fac[i - 1] * i % 167772161;
	S[0][0] = 1;
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= i; ++j)
			S[i][j] = (S[i - 1][j - 1] + (long long)j * S[i - 1][j]) % 167772161;
	for(int i = 0; i <= k; ++i)
		bse.push_back(S[k][k - i]);
	prd.push_back(1);
	int m = n, ans = 0;
	while(m) 
	{
		if(m & 1) 
			prd = mult(prd, bse);
		if(m > 1) 
			bse = mult(bse, bse);
		m >>= 1;
	}
	for(int i = 0; i < n * k; ++i)
		if(i & 1) 
			(ans += 167772161 - (long long)fac[n * k - i] * prd[i] % 167772161) %= 167772161;
		else 
			(ans += (long long)fac[n * k - i] * prd[i] % 167772161) %= 167772161;
	cout << ans << endl;
    return 0;
}
