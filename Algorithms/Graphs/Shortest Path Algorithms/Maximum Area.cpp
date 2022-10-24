#include<bits/stdc++.h>
using namespace std;
int vis[151][151], rr[] = {0, 0, 1, -1}, cc[] = {1, -1, 0, 0};
 
struct cou
{
  	int f, s, t;
};
 
bool operator<(const cou&a, const cou&b)
{
 	return a.t < b.t;
}
 
int dijkstra(int sx, int sy, vector<vector<int>>&v, int t)
{
  	priority_queue<cou>q;
  	q.push({sx, sy, t});
  	int res = 0, n = v.size();
  	memset(vis, 0, sizeof(vis));
  	while(!q.empty())
	{
     	int f = q.top().f, s = q.top().s, t = q.top().t;
     	q.pop();
     	if(vis[f][s])
       		continue;
        vis[f][s] = 1;
     	res=max(res, (max(sx, f) + 1) * (max(sy, s) + 1));
     	for(int h = 0; h < 4; h++)
		{
       		int xx = f + rr[h], yy = s + cc[h];
       		if(xx < n && xx >= 0 && yy < n && yy >= 0 && t - v[xx][yy] >= 0 && vis[xx][yy] == 0)
         		q.push({xx, yy, t - v[xx][yy]});
        }
  	}
  	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int n, t, ans = 0;
  	cin >> n >> t;
  	vector<vector<int>> v(n, vector<int>(n)), rem(n, vector<int>(n, 0));
  	for(int h = 0; h < n; h++)
	{
    	for(int j = 0; j < n; j++)
    		cin >> v[h][j];
  	}
  	priority_queue<cou>q;
  	q.push({0, 0, t});
  	while(!q.empty())
	{
    	int f = q.top().f, s = q.top().s, t = q.top().t;
    	q.pop();
    	if(vis[f][s])
      		continue;
    	vis[f][s] = 1;
    	for(int h = 0; h < 4; h++)
		{
      		int x = f + rr[h], y = s + cc[h];
      		if(x < n && x >= 0 && y < n && y >= 0 && vis[x][y] == 0 && t - v[x][y] >= 0)
        		q.push({x, y, t - v[x][y]});
      	}
      	rem[f][s] = t;
  	}
  	if(rem[n - 1][n - 1])
	{
    	cout << n * n << endl;
    	exit(0);
  	}
  	for(int h = 0; h < n; h++)
	{
    	for(int j = 0; j < n; j++)
		{
      		if(rem[h][j])
			{
        		ans = max(ans, dijkstra(h, j, v, rem[h][j]));
        		if(ans == n * n)
				{
          			cout << ans << endl;
          			exit(0);
        		}
      		}
    	}
  	}
  	cout << ans << endl;
}
