#include <bits/stdc++.h>
int n, m, K, S, fac[5200010], inv[5200010];
using namespace std;
 
inline int pw(int a, int b)
{
	int r = 1;
	for(; b; b>>=1, a = 1ll * a* a % 1000000007)
		if(b & 1)
			r = 1ll * r * a % 1000000007;
	return r;
}
 
inline int get(char c)
{
	return c >= 'a' && c <= 'z' ? c - 'a' + 1 : c - 'A' + 1;
}
 
inline int C(int a, int b)
{
	return a < b ? 0 : 1ll * fac[a] * inv[b] % 1000000007 * inv[a - b] % 1000000007;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char s[200010];
	cin >> n >> m >> K >> s + 1;
	S = n * 26;
	for(int i = 1; i <= n; i++)
		K = (K - get(s[i]) + m) % m;
	fac[0] = 1;
	for(int i = 1; i <= S; i++)
		fac[i] = 1ll * fac[i - 1] * i % 1000000007;
	inv[S] = pw(fac[S], 1000000005);
	for(int i = S - 1; ~i; i--)
		inv[i] = 1ll * inv[i + 1] * (i + 1) % 1000000007;
	int ans = 0;
	for(int v = K; v <= S; v += m)
		for(int i = 0; i <= n && i * 26 < v; i++)
			if(i & 1)
				ans = (ans - 1ll * C(v - i * 26 - 1, n - 1) * C(n, i) % 1000000007 + 1000000007) % 1000000007;
			else 
				ans = (ans + 1ll * C(v - i * 26 - 1, n - 1) * C(n, i)) % 1000000007;
	cout << ans;
	return 0;
}
