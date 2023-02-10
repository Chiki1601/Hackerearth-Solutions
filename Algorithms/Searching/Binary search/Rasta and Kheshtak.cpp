#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n1, m1, n2, m2, i, r, c, ans = 0;
    long long ts = 1000, ml = 1000000, mr = 1000000000, nr;
    cin >> n1 >> m1;
    unordered_map <long long, vector <pair <int, int>>> d;
    int a[n1][m1];
    for(r = 0; r < n1; r++)
        for(c = 0; c < m1; c++)
            cin >> a[r][c];
    for(r = 1; r < n1; r++) 
    {
        for(c = 1; c < m1; c++) 
        {
            nr = a[r - 1][c - 1] * mr + a[r - 1][c] * ml + a[r][c - 1] * ts + a[r][c];
            if(d.find(nr) != d.end())
                d[nr].push_back(make_pair(r, c));
            else 
                d[nr] = {make_pair(r, c)};
        }
    }
    ans = 0;
    int mem[m1][n1];
    for(r = 0; r < n1; r++)
        for(c = 0; c < m1; c++)
            mem[r][c] = 0;
    cin >> n2 >> m2;
    int b[n2][m2];
    for(r = 0; r < n2; r++)
        for(c = 0; c < m2; c++)
            cin >> b[r][c];
    for(r = 1; r < n2; r++) 
    {
        for(c = 1; c < m2; c++) 
        {
            nr = b[r - 1][c - 1] * mr + b[r - 1][c] * ml + b[r][c - 1] * ts + b[r][c];
            if(d.find(nr) != d.end())
                for(auto pr : d[nr])
                    mem[pr.first][pr.second] = 1;
        }
    }
    for(r = 1; r < n1; r++) 
    {
        for(c = 1; c < m1; c++) 
        {
            if(mem[r][c]) 
            {
                mem[r][c] = 1 + min(mem[r][c - 1], min(mem[r - 1][c - 1], mem[r - 1][c]));
                if(mem[r][c] > ans) 
                    ans = mem[r][c];
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
