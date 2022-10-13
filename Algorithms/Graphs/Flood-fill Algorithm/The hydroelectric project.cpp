#include<bits/stdc++.h>
using namespace std;
char v[1002][1002];
int n, m, mask = 1, dx[] = {0, 1}, dy[] = {1, 0}, vis[1002][1002];
 
bool outside(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m)
        return true ;
    return false ;
}
 
void dfs(int x, int y)
{
    vis[x][y] |= mask;
    for(int k = 0; k < 2; k++)
    {
        int xx = x + dx[k], yy = y + dy[k];
        if(outside(xx, yy))
                continue ;
        if(vis[xx][yy] & mask)
                continue ;
        if(v[xx][yy] == '#')
                continue ;
        dfs(xx, yy);
        return ;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c;
        }
    }
    dfs(0, 0);
    mask = 2;
    swap(dx[0], dx[1]);
    swap(dy[0], dy[1]);
    dfs(0, 0);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            if(vis[i][j] == 3)
                ans = min(ans, val);
        }
    }
    cout << ans << "\n";
    return 0 ;
}
