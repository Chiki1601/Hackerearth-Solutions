#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e3 + 14;
bitset<MAX_N> table[MAX_N];
 
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            int x;
            cin >> x;
            table[i + 1][j + 1] = table[i + 1][j] ^ table[i][j] ^ table[i][j + 1] ^ x % 2;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            int c = (table[i] ^ table[j]).count();
            ans += c * (c - 1) / 2 + (m - c + 1) * (m - c) / 2;
        }
    }
    cout << ans << endl;
}
