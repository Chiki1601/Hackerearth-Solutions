#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int n, k; T-- > 0 && cin >> n >> k; ) 
    {
        string s;
        cin >> s;
        int x = 0;
        for (auto ch : s) 
            x ^= ch - '0';
        int t = 0, u = 0, v = -1, z = 1;
        for (int i = n, p = 1; i-- > 1; p = p * 10LL % k) 
        {
            int c = s[i] - '0';
            if (c) 
                z = 0;
                x ^= c;
                t = (t + (LL)c * p % k) % k;
            if (!z && c && 0 == t) 
            {
                if (x >= v) 
                {
                    u = i;
                    v = x;
                }
            }
        }
        if (v < 0) 
            cout << -1 << endl; 
        else 
            cout << s.substr(u) << endl;
    }
    return 0;
}
