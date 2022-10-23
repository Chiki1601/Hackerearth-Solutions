#include<bits/stdc++.h> 
using namespace std;
long long n, ans, fact[100005], inv[100005];
 
inline long long power(long long x, long long y) 
{
    long long res = 1;
    for (; y; (y >>= 1), (x = x * x % 1000000007)) 
    {
        if (y & 1) 
            res = res * x % 1000000007;
    }
    return res;
}
 
inline long long choose(long long x, long long y) 
{
    return (x > y? 0: fact[y] * inv[x] % 1000000007 * inv[y - x] % 1000000007); 
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fact[0] = 1;
    for (long long i = 1; i < 100005; i++) 
        fact[i] = fact[i - 1] * i % 1000000007;
    inv[100004] = power(fact[100004], 1000000005);
    for (long long i = 100003; ~i; i--) 
        inv[i] = inv[i + 1] * (i + 1) % 1000000007;
    cin >> n;
    for (long long i = 0; i <= n; i++) 
        ans = ((ans + (i & 1? -1: 1) * choose(i, n) * power(2, (n - i) * (n - i - 1) / 2) % 1000000007) % 1000000007 + 1000000007) % 1000000007;
    cout << ans;
}
