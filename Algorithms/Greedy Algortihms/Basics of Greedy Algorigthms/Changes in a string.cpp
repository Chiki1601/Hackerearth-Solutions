#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, suf[1000014];
        string s;
        cin >> n >> s;
        suf[n] = 0;
        for(int i = n - 1; i >= 0; i--)
            suf[i] = (s[i] == 'A') + suf[i + 1];
        int pre = 0, ans = n;
        for(int i = 0; i <= n; i++)
        {
            ans = min(ans, pre + suf[i]);
            pre += s[i] == 'B';
        }
        cout << ans << endl;
    }
}
