#include <bits/stdc++.h>
using namespace std;
int n, fac[100014], rfac[100014];
 
int rev(int x)
{
    int ans = 1;
    for(int b = 1000000005; b; b >>= 1, x = (long long) x * x % 1000000007)
        if(b & 1)
            ans = (long long) ans * x % 1000000007;
    return ans;
}
 
int c(int n, int r)
{
    return (long long) fac[n] * rfac[r] % 1000000007 * rfac[n - r] % 1000000007;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fac[0] = rfac[0] = 1;
    for(int i = 1; i < 100014; i++)
	{
        fac[i] = (long long) fac[i - 1] * i % 1000000007;
        rfac[i] = rev(fac[i]);
    }
    int t, n;
    cin >> t;
    while(t--)
	{
        cin >> n;
        int ans = 0;
        for(int i = 0; i * 2 <= n; i++)
            ans = (ans + (long long) c(n, i) * c(n - i, i)) % 1000000007;
        cout << ans << endl;
    }
}
