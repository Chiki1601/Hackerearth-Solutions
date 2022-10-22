#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, requiredOR = 0, ans = 0;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            requiredOR |= a[i];
        }
        vector<int> prefix(n + 2, 0), suffix(n + 2, 0);
        for(int i = 1; i <= n; i++)
            prefix[i] = (prefix[i - 1] | a[i]);
        for(int i = n; i >= 1; i--)
            suffix[i] = (suffix[i + 1] | a[i]);
        for(int i = 1; i <= n; i++)
            if((prefix[i - 1] | suffix[i + 1]) == requiredOR)
                ans = max(ans, a[i]);
        cout << ans << endl;
    }
    return 0;
}
