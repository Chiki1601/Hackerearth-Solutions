#include<bits/stdc++.h>
using namespace std;
 
#ifdef ONLINE_JUDGE
inline void inp(int &n)
{
    n = 0;
    int ch = getchar_unlocked(),  sign = 1;
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            sign = -1; 
            ch = getchar_unlocked();
        }
        while(ch >= '0' && ch <= '9')
            n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
            n *= sign;
}
#else
inline void inp(int &n)
{
    cin >> n;
}
#endif
long long int fact[1000001];
void pre_process()
{
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++)
        fact[i] = (fact[i - 1] * i) % 1000000007;
}
 
int main()
{
    int n, t;
    pre_process();
    inp(t);
    assert(1 <= t && t <= 100000);
    while(t--)
    {
        inp(n);
        assert(1 <= n && n <= 1000000);
        long long int ans = ((3 * fact[n]) % 1000000007 + 3) % 1000000007;
        cout << ans << endl;
    }   
    return 0;
}
