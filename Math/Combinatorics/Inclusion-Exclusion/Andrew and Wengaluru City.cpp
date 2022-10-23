#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, a[100010], b[100010], c[100010];
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        b[0] = a[0];
        for(int i = 1; i < n; i++)
            b[i] = max(a[i], b[i - 1]);
        c[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--)
            c[i] = max(a[i], c[i + 1]);
        long long Max, ans = 0;
        for(int i = 1; i < n - 1; i++)
        {
            Max = min(b[i - 1], c[i + 1]);
            if(a[i] < Max) 
				ans +=  (long long)(Max - a[i]);
        }
        ans %= 1000000007;
        cout << ans << endl;
    }
    return 0;
}
