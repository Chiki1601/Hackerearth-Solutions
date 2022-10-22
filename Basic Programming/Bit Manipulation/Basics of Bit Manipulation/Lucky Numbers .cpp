#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, c = 1000000007;
    cin >> t;
    while (t--)
    {
        long n, j, i = 1, k, ans;;
        cin >> n;
        short b = 0;
        for (j = n; j; j >>= 1)
            b++;
        i <<= b - 1;
        ans = ((b - 2) * ((i - 1) % c)) % c;
        j = 1;
        n -= i;
        while (j <= n)
        {
            ans += (i + j);
            ans %= c;
            j <<= 1;
        }
        cout << ans << endl;
    }
    return 0;
}
