#include <bits/stdc++.h>
using namespace std;
 
void solve() 
{
    string str;
    cin >> str;
    int n = str.size();
    int b[n + 1], cnt = 0;
    for(int i = 0; i < n; i++) 
    {
        b[i] = (str[i] == 'K' ? 1 : -1);
        cnt += (str[i] == 'R');
    }
    int gMax = b[0], lMax = b[0];
    for(int i = 1; i < n; i++) 
    {
        lMax = max(b[i], lMax + b[i]);
        gMax = max(lMax, gMax);
    }
    cout << cnt + gMax << endl;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
