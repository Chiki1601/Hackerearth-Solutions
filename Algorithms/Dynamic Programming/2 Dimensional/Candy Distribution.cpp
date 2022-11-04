#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> m;
 
long long fpow(long long n, long long b)
{
    long long res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * 1ll * n) % 1000000007;
        n = (n * 1ll * n) % 1000000007;
        b >>= 1;
    }
    return res;
}
 
long long rec(long long n)
{
    if(n <= 2)
        return 1;
    if(m.find(n) != m.end())
        return m[n];
    n--;
    long long ans = 0;
    for(int i = 1; i * 1ll * i <= n; i++)
    {
        if(n % i)
            continue;
        long long x = i, y = n / i;
        if(n / x >= 2)
            ans = (ans + fpow(rec(x), n / x)) % 1000000007;
        if(x != y && (n / y) >= 2)
            ans = (ans + fpow(rec(y), n / y)) % 1000000007;
    }
    return m[n + 1] = ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;
    m[1] = m[2] = 1;
    cout << rec(n) << endl;
   return 0;
}
