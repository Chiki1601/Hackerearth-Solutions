#include<bits/stdc++.h>
using namespace std;
int T, n, z, fac[200005], inv[200005];
 
inline int ksm(int x, int y)
{
	int ans1 = 1;
    while(y)
    {
		if(y & 1) 
        ans1 = 1ll * ans1 * x % 1000000007;
		y>>=1;
        x = 1ll * x * x % 1000000007;
	}
    return ans1;
}
 
inline int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % 1000000007 * inv[n - m] % 1000000007;
}
 
int main()
{
	fac[0] = 1;
	for(int i = 1; i < 200005; i++) 
        fac[i] = 1ll * fac[i - 1] * i % 1000000007;
	inv[200004] = ksm(fac[200004], 1000000005);
	for(int i = 200003; ~i; i--) 
        inv[i] = 1ll * inv[i + 1] * (i + 1) % 1000000007;
	cin >> T;
	while(T--)
    {
		cin >> n >> z;
		int ans = 0;
		for(int i = 1; i <= z; i++)
        {
			int res = z / i;
			if(res < n) 
                break;
			ans += C(res - 1, n - 1);
			ans %= 1000000007;
		}
		cout << ans << "\n";
	}
	return 0;
}
