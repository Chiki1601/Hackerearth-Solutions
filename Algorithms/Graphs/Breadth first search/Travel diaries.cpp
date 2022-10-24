#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int x, y, t;
    node(int _x, int _y, int _time)
    {
        x = _x;
        y = _y;
        t = _time;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, count1 = 0;
    cin >> n >> m;
    int grid[n][m];
    queue<node> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 2)
                q.push(node(i, j, 0));
            if(grid[i][j] == 1)
                count1++;
        }
    }
    int ans = 0, count = 0;
    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y, t = q.front().t;
        q.pop();
        ans = max(ans, t);
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
            {
                grid[newX][newY] = 2;
                count++;
                q.push(node(newX, newY, t + 1));
            }
        }
    }
    if(count1 == count)
        cout << ans << endl;
    else
      cout << -1 << endl;
}
