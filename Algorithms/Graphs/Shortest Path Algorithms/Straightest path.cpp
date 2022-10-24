#include <bits/stdc++.h>
using namespace std;
int val[1000][1000][4], dx[]= {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, sx, sy, tx, ty, ans = -1;
    cin >> n >> m;
    char field[1000][1000];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> field[i][j];
            if(field[i][j] == 'V')
            {    
                sx = i; 
                sy = j;
            }
            if(field[i][j] == 'H')
            {    
                tx = i;
                ty = j;
            }
            for(int k = 0; k < 4; k++) 
                val[i][j][k] = INT_MAX;
        }
    }
    deque<tuple<int, int, int>>q;
    for(int i = 0; i < 4; i++)
    {
        q.emplace_back(sx, sy, i);
        val[sx][sy][i] = 0;
    }
    while(!q.empty())
    {
        auto[x, y, d] = q.front();
        q.pop_front();
        if(x == tx && y == ty)
        {
            ans = val[x][y][d];
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] != '*')
            {
                if(val[nx][ny][i] > val[x][y][d] + (i != d))
                {
                    val[nx][ny][i] = val[x][y][d] + (i != d);
                    if(i == d) 
                        q.emplace_front(nx, ny, i);
                    else 
                        q.emplace_back(nx, ny, i);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
