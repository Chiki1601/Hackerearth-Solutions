#include<bits/stdc++.h>
using namespace std;
 
long long power(long long x, long long y)
{
    long long res = 1;
    x %= 1000000007;
    if(x == 0) 
        return 0; 
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % 1000000007;
        y = y>>1;
        x = (x * x) % 1000000007;
    }
    return res;
}
 
long long f(long long n)
{
    long long x = power(3, n - 2), y = ((n % 1000000007) * ((n + 2) % 1000000007)) % 1000000007;
    return (x * y) % 1000000007;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tt = 1; 
    cin >> tt;
    while(tt--)
    {
        long long n; 
        cin >> n;
        if(n == 1)
            cout << "1" << endl;
        else
            cout << f(n) << endl;
    }
    return 0;
}
