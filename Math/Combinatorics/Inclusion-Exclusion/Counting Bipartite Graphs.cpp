#include<bits/stdc++.h>
using namespace std;
long long fac[1000003], bp[1000003];
 
long long BigMod(long long b, long long p, long long m) 
{
    long long r = 1;
    while(p) 
    {
        if(p & 1)
            r = (r * b) % m;
        b = (b * b) % m;
        p>>=1;
    }
    return r;
}
 
long long nCk(int n,int k) 
{
    return (fac[n] * ((BigMod(fac[k], 998244351LL, 998244353LL) * BigMod(fac[n - k],998244351LL, 998244353LL)) % 998244353LL)) % 998244353LL;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fac[0] = bp[0] = 1;
    for(long long i = 1; i <= 1000001; i++) 
    {
        fac[i] = (fac[i - 1] * i) % 998244353LL;
        bp[i] = (bp[i - 1] * 2) % 998244353LL;
    }
    long long n, m;
    cin >> n >> m;
    long long tot = BigMod((bp[m] - 1 + 998244353LL) % 998244353LL, n, 998244353LL);
    for(int i = 1; i <= m; i++) 
    {
        long long ways = (nCk(m, i) * BigMod((bp[m - i] - 1 + 998244353LL) % 998244353LL, n, 998244353LL)) % 998244353LL;
        if(i & 1)
            tot = (tot - ways + 998244353LL) % 998244353LL;
        else 
            tot = (tot + ways) % 998244353LL;
    }
    cout << (tot + 998244353LL) % 998244353LL << endl;
    return 0;
}
