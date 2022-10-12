#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int p[n], w[n], wmax, cc, ans = -1;
    for (int i = 0; i < n; i++)
        cin >> p[i] >> w[i];
    cin >> wmax >> cc;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0, wt = 0, c = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                wt += w[j];
                c++;
                sum += p[j];
            }
        }
        if (c <= cc)
        {
            if (wt <= wmax && sum > 0)
                ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
 
int main()
{
    int t = 1, i = 1;
    cin >> t;
    while (t--)
    {
        cout << "For Day #" << i++ << ":" << endl;
        solve();
    }
    return 0;
}
