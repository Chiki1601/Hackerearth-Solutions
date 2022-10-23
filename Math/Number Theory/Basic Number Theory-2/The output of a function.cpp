#include <bits/stdc++.h>
using namespace std;
 
long long power(long long a, long long n, long long c)
{
    if(n == 0) 
        return 1 % c;
    long long s = power(a, n / 2, c);
    s = (s * s) % c;
    if(n % 2) 
        s = (s * a) % c;
    return s;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t;
    cin >> t;
    while(t--)
    {
        long long p, q, r, ans = 0;
        cin >> p >> q >> r;
        ans += power(r, p * q, 1000000007);
        ans = (ans - 1 + 1000000007) % 1000000007;
        long long deno = (power(r, p, 1000000007) - 1 + 1000000007) % 1000000007;
        deno *= (power(r, p * q, 1000000007));
        deno %= 1000000007;
        ans *= power(deno, 1000000005, 1000000007);
        ans %= 1000000007;
        cout << ans << endl;
    }
    return 0;
}
