#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;
        vector<long> v(n);
        for(int i = 0; i < n; ++i)
            cin >> v[i];
        long curSt = v[0], ans = 0;
        for(int i = 1; i < n; ++i)
            (v[i] >= v[i - 1]) ? (ans = max(ans, v[i] - curSt)) : (curSt = v[i]);
        curSt = v[0];
        for(int i = 1; i < n; ++i)
            (v[i] <= v[i - 1]) ? (ans = max(ans, curSt - v[i])) : (curSt = v[i]);
        reverse(v.begin(), v.end());
        curSt = v[0];
        for(int i = 1; i < n; ++i)
            (v[i] >= v[i - 1]) ? (ans = max(ans, v[i] - curSt)) : (curSt = v[i]);
        curSt = v[0];
        for(int i = 1; i < n; ++i)
            (v[i] <= v[i - 1]) ? (ans = max(ans, curSt - v[i])) : (curSt = v[i]);
        cout << ans << endl;
    }
}
