#include<bits/stdc++.h>
using namespace std;

long long int mod_exp(long long int b, long long int p, long long int m)
{
    long long int x = 1;
    while(p)
    {
        if(p & 1)
            x = (x * b) % m;
        b = (b * b) % m;
        p = p>>1;
    }
    return x;
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t; 
    cin >> t;
    while(t--)
    {   
        long long int n, ans = 0, pos = 1LL; 
        cin >> n;
        vector<long long int> a(n), subs(n, 0);
        for(long long int i = 0; i < n; i++)
            cin >> a[i];
        for(long long int i = 1; i < n; i++)
            subs[i] = (a[i] * mod_exp(2LL, n - i - 1, 1000000007)) % 1000000007;
        for(long long int i = n - 2; i >= 1; i--)
            subs[i] = (subs[i] + subs[i + 1]) % 1000000007;
        for(long long int i = 0; i < n - 1; i++)
        {
            long long int ok = (subs[i + 1] * pos) % 1000000007;
            ok = (ok % 1000000007);
            ok = (a[i] * ok) % 1000000007;
            ans = (ans + ok) % 1000000007;
            pos = (pos * 2LL) % 1000000007;
        }
        cout << ans << "\n";
    }
    return 0;
}
