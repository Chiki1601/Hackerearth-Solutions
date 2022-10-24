#include <bits/stdc++.h>
using namespace std;
int grid[1005][1005], dist[1005][1005], n, m, dr[] = {0, 0, -1, 1}, dc[] = {-1, 1, 0, 0};
bool vis[1005][1005]; 
 
int bfs(int fromX, int fromY)
{
    queue <pair<int, int> > q;
    pair <int, int> p;
    dist[fromX][fromY] = 0;
    q.push({fromX, fromY});
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        fromX = p.first;
        fromY = p.second;
        if(fromX == 0 or fromX == n - 1 or fromY == 0 or fromY == m - 1)
            return dist[fromX][fromY];
        for(int i = 0; i < 4; ++i)
        {
            int x = fromX + dr[i], y = fromY + dc[i];
            if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != 1 and vis[x][y] == false)
            {
                vis[x][y] = true;
                dist[x][y] = dist[fromX][fromY] + 1;
                q.push({x, y});
            }
        }
    }
    return -1;
}
 
int main()
{
    int ans, x, y;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            vis[i][j] = false;
            dist[i][j] = 0;
            if(grid[i][j] == 2)
                x = i, y = j;
        }
    ans = bfs(x, y);
    cout << ans << endl;
    return 0;
}
