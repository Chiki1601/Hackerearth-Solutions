#include <bits/stdc++.h>
using namespace std;
int n, a[200014], ans;
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans = max(ans, i - a[i]);
    }
    cout << ans + 1 << endl;
}
