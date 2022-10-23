#include<bits/stdc++.h>
using namespace std;
 
long long int modpow(long long int a, long long int q, long long int MOD) 
{
    a %= MOD;
    if(q == 0) 
        return 1;
    return ((q % 2 == 1 ? a : 1) * modpow(a * a, q / 2, MOD)) % MOD;
}
 
long long int inv(long long int a)
{
    return modpow(a, 1000000005, 1000000007);
}
 
int main()
{
    long long int t = 1;
    vector<long long int> fact(1000001);
    fact[0] = 1;
    for(long long i = 1; i < 1000001; i++)
        fact[i] = (fact[i - 1] * i) % 1000000007;
    cin >> t;  
    while(t--)
    {
        long long int n, x, y;
        cin >> n >> x >> y;
        long long int ans = ((fact[n] * inv(fact[x])) % 1000000007 * inv(fact[y])) % 1000000007;
        ans = ((ans * (x - y)) % 1000000007 * inv(x + y)) % 1000000007;
        cout << ans << endl;
    }
    return 0;
}
