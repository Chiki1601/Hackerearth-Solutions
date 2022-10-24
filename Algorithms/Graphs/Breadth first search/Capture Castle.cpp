#include <bits/stdc++.h>
using namespace std;
int n, m, ex, ey, et, g[1005][1005], cost[1005][1005], dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
 
void bfs(int sx, int sy)
{
    queue<pair<int, int>>q;
    q.push({0, 0});
    cost[sx][sy] = g[0][0];
    while(!q.empty())
	{
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i)
		{
            int nx = x + dr[i], ny = y + dc[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && cost[nx][ny] > cost[x][y] + g[nx][ny])
			{
                cost[nx][ny] = cost[x][y] + g[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    if(cost[ex][ey] <= et)
    	cout << "YES" << endl << et - cost[ex][ey] << endl;
    else
    	cout << "NO" << endl; 
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, vis[1005][1005];
	cin >> t;
    while(t--)
	{
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> g[i][j];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
			{
                vis[i][j] = 0;
                cost[i][j] = 1000000000;
            }
        cin >> ex >> ey >> et;
        ex--, ey--;
        bfs(0, 0);
    }
}
