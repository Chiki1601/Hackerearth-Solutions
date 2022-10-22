#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long t;
    cin >> t;
    assert(1 <= t && t <= 10);
    while(t--)
    {
        long long n, m, i, suma = 0, sumb = 0, sumc = 0, sumd = 0, q;
        cin >> n >> m;
        assert(1 <= n && n <= 100000);
        assert(1 <= m && m <= 100000);
        vector<int> a(n + 1), b(m + 1);
        for(i = 1; i <= n ; i++)
        {
            cin >> a[i];
            assert(1 <= a[i] && a[i] <= 1000000);
        }
        for(i = 1; i <= m ; i++)
        {
            cin >> b[i];
            assert(1 <= b[i] && b[i] <= 1e6);
        }
        vector<long long> c(n + 1), d(m + 1);
        for(i = 1 ; i <= n; i++)
            c[i] = i * a[i] % 998244353;
        for(i = 1 ; i <= m ; i++)
            d[i] = i * b[i] % 998244353;
        for(i = 1 ; i <= n; i++)
        {
            suma += a[i]; 
            sumc += c[i]; 
            suma %= 998244353; 
            sumc %= 998244353;
        }
        for(i = 1 ; i <= m; i++)
        {    
            sumb += b[i]; 
            sumd += d[i]; 
            sumb %= 998244353; 
            sumd %= 998244353;
        }
        cout << (sumc * sumb % 998244353 + suma * sumd % 998244353) % 998244353;
        cin >> q;
        assert(1 <= q && q <= 100000);
        for(i = 1 ; i <= q ; i++)
        {
            long long tp, u, v;
            cin >> tp >> u >> v;
            assert(1 <= tp && tp <= 3);
            if(tp == 1)
            {
                assert(1 <= u && u <= n);
                assert(1 <= v && v <= m);
                suma -= a[u];
                sumb -= b[v];
                sumc -= c[u];
                sumd -= d[v];
                long long temp = a[u];
                a[u] = b[v];
                b[v] = temp;
                c[u] = u * a[u] % 998244353;
                d[v] = v * b[v] % 998244353;
                suma = (suma + a[u]) % 998244353;
                sumb = (sumb + b[v]) % 998244353;
                sumc = (sumc + c[u]) % 998244353;
                sumd = (sumd + d[v]) % 998244353;
            }
            else if(tp == 2)
            {
                assert(1 <= u && u <= n);
                assert(1 <= v && v <= n);
                sumc -= c[u];
                sumc -= c[v];
                long long temp = a[u];
                a[u] = a[v];
                a[v] = temp;
                c[u] = u * a[u] % 998244353;
                c[v] = v * a[v] % 998244353;
                sumc = (sumc + c[u]) % 998244353;
                sumc = (sumc + c[v]) % 998244353;
            }
            else
            {
                assert(1 <= u && u <= m);
                assert(1 <= v && v <= m);
                sumd -= d[u];
                sumd -= d[v];
                long long temp = b[u];
                b[u] = b[v];
                b[v] = temp;
                d[u] = u * b[u] % 998244353;
                d[v] = v * b[v] % 998244353;
                sumd = (sumd + d[u]) % 998244353;
                sumd = (sumd + d[v]) % 998244353;
            }
            cout << " " << ((sumc * sumb % 998244353 + suma * sumd % 998244353) % 998244353 + 998244353) % 998244353; 
        }
        cout << endl;
    }
}
