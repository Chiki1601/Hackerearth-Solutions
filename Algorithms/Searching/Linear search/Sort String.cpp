#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
	{
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> l(n), r(n);
        l[0] = s[0] - '0';
        for(int i = 1; i < n; i++) 
            l[i] = l[i - 1] + s[i] - '0';
        r[n - 1] = s[n - 1] - '0';
        for(int i = n - 2; i >= 0; i--) 
            r[i] = r[i + 1] + s[i] - '0';
        int ans = min(l[n - 1], n - l[n - 1]);
        for(int i = 1; i < n; i++) 
            ans = min(ans, l[i - 1] + n - i - r[i]);
        cout << (ans + 1) / 2 << "\n";
    }
    return 0;
}
