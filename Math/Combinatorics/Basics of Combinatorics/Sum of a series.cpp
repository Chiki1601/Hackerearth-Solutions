#include<bits/stdc++.h>
using namespace std;
 
long long modexp(long long x, long long n)
{
    if(n == 0)
		return 1ll;
    if(n == 1)
		return x % 1000000021;
    long long y = modexp(x, n / 2);
    if(n % 2 == 0)
		return (y * y) % 1000000021;
    else 
		return (((y * y) % 1000000021) * x) % 1000000021;
}
 
long long add(long long x, long long p)
{
    x = (x % 1000000021 + p % 1000000021) % 1000000021;
    x = (x + 1000000021) % 1000000021;
    return x;
}
 
long long sub(long long x, long long p)
{
    x = (x % 1000000021 - p % 1000000021) % 1000000021;
    x = (x + 1000000021) % 1000000021;
    return x;
}
 
long long mul(long long x, long long p)
{
    x = ((x % 1000000021) * (p % 1000000021)) % 1000000021;
    return x;
}
 
long long divide(long long x, long long p)
{
    x = ((x % 1000000021) * modexp(p % 1000000021, 1000000019)) % 1000000021;
    return x;
}
 
long long helper(long long z, long long n)
{
    z %= 1000000021;
    long long x = sub(mul(n % 1000000021, z), 1ll);
    x = mul(x, modexp(add(z, 1ll), n));
    x = add(x, 1ll);
    x = divide(x, mul(add(n % 1000000021, 1ll), mul(z, z)));
    return x;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long t;
    cin >> t;
    assert(1ll <= t && t <= 100000ll);
    while(t--)
    {
        long long n, k, ans, root3ik, one_plus_root3ik, one_minus_root3ik, a1, a2, pre;
        cin >> n >> k;
        assert(1ll <= n && n <= 1000000000000000000ll);
        assert(0ll <= k && k <= 1000000000000000000ll);
        if(n == 1)
        {
            cout << "0" << endl;
            continue;
        }
        root3ik = mul(mul(589781815, 484563811), k % 1000000021);
        one_plus_root3ik = add(1ll, root3ik);
        one_minus_root3ik = sub(1ll, root3ik);
        pre = mul(root3ik, modexp(2ll, n - 2));
        a1 = helper(divide(one_plus_root3ik, 2ll), n);
        a2 = helper(divide(one_minus_root3ik, 2ll), n);
        ans = mul(pre, sub(a1, a2));
        cout << ans << endl;
    }
    return 0;
}
