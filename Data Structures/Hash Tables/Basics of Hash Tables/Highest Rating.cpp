#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, q, n, mn = 0, mx = 0;
    cin >> m >> q >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int cnt[mx + m * q + 1] = {0}, ans = 0;
    for(int i = 0; i < n; ++i)
    {
        cnt[a[i]]++;
        for(int j = 1; j <= q; ++j)
        {
            cnt[a[i] + j * m]++;
            ans = max(ans, cnt[a[i] + j * m]);
            if(a[i] - j * m >= 0)
            {
                cnt[a[i] - j * m]++;
                ans = max(ans, cnt[a[i] - j * m]);
            }
        }
    }
    cout << ans << endl;
}
