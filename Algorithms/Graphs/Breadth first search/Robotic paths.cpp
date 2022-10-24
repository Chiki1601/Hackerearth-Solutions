#include<bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
char dir[]={'D','L','R','U'};
 
bool valid(int x, int y, vector<vector<int>> &vis, int n, int m, string s[])
{ 
	if(x >= n || y >= m || x < 0 || y < 0)
		return false;
	if(vis[x][y] == 1)
		return false;
	if(s[x][y] == '#')
		return false;
	return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++)
        cin >> s[i];
    int Q;
    cin >> Q;
    while(Q--)
    {
        int sx, sy, fx, fy;
        cin >> sx >> sy >> fx >> fy;
        sx--,sy--,fx--,fy--;
		vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        queue<string>str;
        string ans = "Impossible";
        q.push(make_pair(sx, sy));
        vis[sx][sy] = 1;
        str.push("");
        while(!q.empty())
        {
            pair<int, int>p = q.front();
            if(p.first == fx && p.second == fy)
            {
                ans = str.front();
                break;
            }
            q.pop();
            string temp = str.front();
            str.pop();
            for(int i = 0; i < 4; i++)
            {
                if(valid(p.first+dx[i], p.second + dy[i], vis, n, m, s))
                {
                    q.push(make_pair(p.first + dx[i], p.second+dy[i]));
                    vis[p.first + dx[i]][p.second + dy[i]] = 1;
                    string flag = temp + dir[i];
                    str.push(flag);
                }
            }
        }
        cout << ans << endl;
    }
}
