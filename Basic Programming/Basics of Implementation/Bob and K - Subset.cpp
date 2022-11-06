#include <bits/stdc++.h>
#define  mod 100000000000
using namespace std;
 
int power(int x, int y)
{
    int res = 1;
    x %= mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1; // y = y/2
        x = (x * x) % mod;
    }
    return res % mod;
}
 
int inv(int n)
{
    return power(n, mod - 2) % mod;
}
 
int n, k, a[2005], b[25][4005];
 
int32_t main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, l;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> a[i], b[1][a[i]] = 1;
    for(i = 1; i < k; i++)
    {
        for(j = 1; j <= 2047; j++)
        {
            if(b[i][j])
            {
                for(l = 1; l <= n; l++)
                    b[i + 1][j|a[l]] = 1;
            }
        }
    }
    int ans = 0;
    for(i = 0; i <= 2047; i++)
        ans += b[k][i];
    cout << ans << endl;
}
