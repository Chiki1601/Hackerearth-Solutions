#include <bits/stdc++.h>
using namespace std;
const int N = 1E3 + 5;
string mat[N];
 
bool f(int x, int y, int n, int m) 
{
    for(int i = x; i < x + 8; i ++) 
        for(int j = y; j < y + 7; j ++) 
            if(mat[i][j] == mat[i][j + 1] || (i < x + 7 && mat[i][j] == mat[i + 1][j]))
                return 0;
    return 1;
}
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> mat[i];
    int cnt = 0;
    for(int i = 0; i < n; i ++) 
        for(int j = 0; j < m; j ++) 
            if(i + 8 <= n && j + 8 <= m && f(i, j, n, m))
                cnt ++;
    cout << cnt;
    return 0;
}
