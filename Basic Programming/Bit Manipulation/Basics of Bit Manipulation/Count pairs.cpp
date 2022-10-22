#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        long long x, y;
        cin >> x >> y;
        long long a[n], b[n], c[1000002] = {0}, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            c[(a[i] & x) ^ (a[i] & y)]++;
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            ans += c[(b[i] & x) ^ (b[i] & y)];
        }
        cout << ans << endl;
    }
    return 0;
}
