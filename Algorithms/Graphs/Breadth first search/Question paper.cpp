#include<bits/stdc++.h>
using  namespace std;
 
long long  power(long long  a, long long  b)
{
    long long  res = 1;
    while(b != 0)
    {
        if(b % 2 != 0)
            res = (res * a);  //%1000000007;
        b /= 2;
        a = (a * a);  //%1000000007;
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        long long  ans = 0, st = n + 1;
        int nc = (b + a) / __gcd(a, b);
        if(n < nc)
            nc = n + 2;
        ans = (nc * (2 * st + - nc + 1)) / 2;
        cout << ans << endl;
    }
}
