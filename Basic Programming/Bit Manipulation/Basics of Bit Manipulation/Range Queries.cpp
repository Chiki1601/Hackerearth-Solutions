#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    for(int i = 1; i <= tt; i++)
    {
        vector<vector<int>> c(100001, vector<int>(20, 0));    
        for(int i = 1; i <= 100000; i++)
            for(int j = 0; j < 20; j++)
                c[i][j] = c[i - 1][j] + (!!(i & (1<<j)));
        int q;
        cin >> q;
        while(q--)
        {
            int l, r, x;
            cin >> l >> r >> x;
            cout << c[r][x - 1] - c[l - 1][x - 1] << "\n";
        }
    }
}
