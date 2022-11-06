#include <bits/stdc++.h>
using namespace std;
 
long long p(long long n, long long p)
{
    long long r = 1;
    while(p)
    {
        if(p & 1) 
        {
            r = (r * n) % 1000000007;
            p--;
        }
        p /= 2;
        n = (n * n) % 1000000007;
    }
    return r;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int d = 1, t = 1;
    cin >> t;
    while(t--)
    {
        long long i, j, k, l, x = 0, y = 0, n, q;
        cin >> n >> q;
        int a[n + 1];
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(a[i] % 2)
                x++;
            else
                y++;
        }
        for(i = 1; i < n; i++)
            cin >> j >> k;
        while(q--)
        {
            cin >> j >> k;
            if(a[j] % 2)
                x--;
            else
                y--;
                a[j] = k;
            if(a[j] % 2)
                x++;
            else
                y++;
            cout << x * (x + 1) / 2 + y * (y + 1) / 2 << " ";
        }
        cout << endl;
    }
}
