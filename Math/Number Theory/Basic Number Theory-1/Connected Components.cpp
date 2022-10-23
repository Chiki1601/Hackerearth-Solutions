#include<bits/stdc++.h>
using namespace std;
int N, M, C, fact[100001], ifact[100001];
 
int gcd(int a, int b, int c, int d, int e, int f)
{
    if(!b)
        return c;
    int k = a / b;
    return gcd(b, a - k * b, d, c - k * d, f, e - k * f);
}
 
int choose(int n, int k)
{
    if(n < k)
        return 0;
    return 1LL * fact[n] * ifact[k] % 1000000007 * ifact[n - k] % 1000000007;
}
     
int main()
{
    fact[0] = 1;
    for(int i = 1; i <= 100000; i++)
        fact[i] = 1LL * fact[i - 1] * i % 1000000007;
    ifact[100000] = (gcd(fact[100000], 1000000007, 1, 0, 0, 1) % 1000000007 + 1000000007) % 1000000007;
    for(int i = 99999; i >= 0; i--)
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % 1000000007;
    int TEST;
    cin >> TEST;
    while(TEST--)
    {
        cin >> N >> M >> C;
        if(C == 0)
            printf("%d\n", N==M);
        else
            cout << 1LL * choose(N - M - 1, C - 1) * choose(M + 1, C) % 1000000007 << endl;
    }
    return 0;
}
