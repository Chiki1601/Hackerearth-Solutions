#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, ans = 0, a[26] = {};
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++)
            a[s[i] - 'a']++;
        for(int i = 0; i < 26; i++)
            ans += a[i] / 2;
        cout << ans << endl;
    }
    return 0;
}
