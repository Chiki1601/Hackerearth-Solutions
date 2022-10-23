#include <bits/stdc++.h>
using namespace std;
 
long long POW_M (long long x, long long y)
{
    long long Res = 1;
    for( ; y ; y /= 2, x = x * x % 1000000007)
        if(y % 2)
            Res = Res * x % 1000000007;
    return Res % 1000000007;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long t, n, a, b, ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        a = POW_M(2, n);
        b = (2 * POW_M(3, n)) % 1000000007;
        ans = (((a * a) % 1000000007) + a - b + 1000000007) % 1000000007;
        cout << ans << "\n";
    }
    return 0;
}
