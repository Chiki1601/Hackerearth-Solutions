#include <bits/stdc++.h>
using namespace std;
 
void solve() 
{
    int n, m;
    cin >> n >> m;
    vector<string> grid1(n), grid2(n);
    for(int i = 0; i < n; i++)
        cin >> grid1[i];
    for(int i = 0; i < n; i++)
        cin >> grid2[i];
    auto flip = [&](char ch) 
    { 
        return (ch == 'A' ? 'B' : 'A'); 
    };
    for(int flipRowOne = 0; flipRowOne < 2; flipRowOne++) 
    {
        vector<bool> colFlipped(m);
        for(int col = 0; col < m; col++) 
        {
            char ch = (flipRowOne ? flip(grid1[0][col]) : grid1[0][col]);
            if(ch != grid2[0][col])
                colFlipped[col] = true;
        }
        bool contradiction = false;
        for(int row = 0; row < n; row++) 
        {
            bool flipRow = false, noFlipRow = false;
            for(int col = 0; col < m; col++) 
            {
                char ch = (colFlipped[col] ? flip(grid1[row][col]) : grid1[row][col]);
                if(ch != grid2[row][col])
                    flipRow = true;
                else
                    noFlipRow = true;
            }
            if(flipRow && noFlipRow)
                contradiction = true;
        }
        if(!contradiction) 
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main() 
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}
