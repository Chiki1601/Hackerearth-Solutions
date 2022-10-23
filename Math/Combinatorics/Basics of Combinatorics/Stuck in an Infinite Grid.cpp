#include <bits/stdc++.h>
using namespace std;
long long prime[400004], k, fact[400004], inv[400004];
 
long long power(long long n, long long p, long long m = 1000000007)
{
    long long r = 1;
    while(p)
    {
        if(p & 1)
        {
            r = (r * n) % m;
            p--;
        }
        p /= 2;
        n = (n * n) % m;
    }
    return r;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int d = 1, t = 1;
    cin >> t;
    fact[0] = inv[0] = 1;
    for(long long i = 1; i < 400004; i++)
    {
        fact[i] = (i * fact[i - 1]) % 1000000007;
        inv[i] = power(fact[i], 1000000005);
    }
    long long i, j;
    while(t--)
    {
        long long i, j, k, l, n, m, r, x, y, x1, y1, h, v;
        cin >> x >> y >> x1 >> y1 >> k;
        h = abs(x - x1);
        v = abs(y - y1);
        if(h + v > k)
            cout << 0 << endl;
        else
        {
            l = 0;
            for(i = h; i <= k; i++)
            {
                j = i;
                m = k - i;
                if(m < v)
                    continue;
                if((j - h) % 2 == 0 && (m - v) % 2 == 0)
                {
                    x = j + m;
                    l = (l + fact[x] * inv[h + (j - h) / 2] % 1000000007 * inv[(j - h) / 2] % 1000000007 * inv[v + (m - v) / 2] % 1000000007 * inv[(m - v) / 2] % 1000000007) % 1000000007;
                }
            }
            cout << l << endl;
        }
    }
}
