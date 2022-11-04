#include <bits/stdc++.h>
using namespace std;
int n, m;
long long sc[26][26], dp[26];
string s;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s >> m;
    while(m--)
    {
        char a, b;
        int s;
        cin >> a >> b >> s;
        sc[a - 'a'][b - 'a'] += s;
    }
    memset(dp, -63, sizeof dp);
    for(auto c : s)
    {
        long long nw = 0;
        for(int p = 0; p < 26; p++)
            nw = max(nw, dp[p] + sc[p][c - 'a']);
        dp[c - 'a'] = max(dp[c - 'a'], nw);
    }
    cout << *max_element(dp, dp + 26) << endl;
}
