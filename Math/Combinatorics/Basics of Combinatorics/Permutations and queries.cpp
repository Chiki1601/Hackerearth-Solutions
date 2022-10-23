#include <bits/stdc++.h>
using namespace std;
int dp[505][505 * 505 / 2], fac[505], c[505][505];
 
template<class T> inline int chkmin(T& a, const T& val) 
{
	return val < a ? a = val, 1 : 0;
}
 
inline void addmod(int& a, int val, int p = 1000000007) 
{
	if((a = (a + val)) >= p) 
		a -= p;
}
 
inline void submod(int& a, int val, int p = 1000000007) 
{
	if((a = (a - val)) < 0) 
		a += p;
}
 
inline int mult(int a, int b, int p = 1000000007) 
{
	return (long long) a * b % p;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fac[0] = 1; 
	for(int i = 1; i < 505; ++i)
		fac[i] = mult(fac[i - 1], i);
    for(int i = 0; i < 505; ++i)
		c[0][i] = 1;
    for(int i = 1; i < 505; ++i)
		for(int j = 1; j < 505; ++j)
			c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % 1000000007;
    dp[0][0] = 1;
    for(int i = 1; i < 505 * 505 / 2; ++i)
		addmod(dp[0][i], dp[0][i - 1]);
    for(int i = 1; i < 505; ++i)
	{
        for(int j = 0; j < 505 * 505 / 2; ++j)
		{
            int lo = max(0, j - i + 1), hi = j;
            dp[i][j] = dp[i - 1][hi];
            if(lo) 
				submod(dp[i][j], dp[i - 1][lo - 1]);
        }
        for(int j = 1; j < 505 * 505 / 2; ++j)
			addmod(dp[i][j], dp[i][j - 1]);
    }
    int q; 
	cin >> q;
    assert(1 <= q && q <= 1e5);
    while (q--) 
	{
        int n, k, res = 0; 
		cin >> n >> k;
        assert(1 <= n && n <= 500);
        assert(0 <= k && k <= 500 * 500);
        chkmin(k, 505 * 505 / 2 - 1);
        for(int i = 1; i < n + 1; ++i)
            addmod(res, mult(n - i + 1, mult(c[i][n], mult(fac[n - i], dp[i][k]))));
        cout << res << endl;
    }
    return 0;
} 
