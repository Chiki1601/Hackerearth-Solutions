#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) 
    {
        long n, q, l, r;
        cin >> n >> q;
        vector<long> v(n+1);
        unordered_map<long, int> board;
        for (int i = 1; i <= n; ++i) 
        {
            cin >> v[i];
            ++board[v[i]];
        }
        while (q--) 
        {
            cin >> l >> r;
            --board[v[l]];
            if (board[v[l]] == 0)
                board.erase(v[l]);
            v[l] = r;
            ++board[v[l]];
            cout << board.size() + 1 << endl;
        }
    }
}
