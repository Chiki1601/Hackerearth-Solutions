#include <bits/stdc++.h>
using namespace std;
int X[] = {0, 0, 1, -1}, Y[] = {-1, 1, 0, 0}, vis[1005][1005], cnt[1000005], mrk[1000005];
string s[1005];
 
bool valid(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < n && s[x][y] == '.');
}
 
void dfs(int x, int y, int n, int m, int p)
{
    if(vis[x][y] != -1)
        return;
    vis[x][y] = p;
    cnt[p]++;
    int i, tx, ty;
    for(i = 0; i < 4; ++i) 
	{
        tx = x + X[i];
        ty = y + Y[i];
        if(valid(tx, ty, n, m))
            dfs(tx, ty, n, m, p);
    }
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(vis, -1, sizeof(vis));
    int n, m, i, j, k, tx, ty;
    cin >> n;
    for(i = 0; i < n; ++i)
        cin >> s[i];
    m = s[0].size();
    for(i = 0; i < n; ++i) 
	{
        for(j = 0; j < m; ++j) 
		{
            if(s[i][j] == '*')
                continue;
            dfs(i, j, n, m, i * m + j);
        }
    }
    long long int ans = 0;
    for(i = 0; i < n; ++i) 
	{
        for(j = 0; j < m; ++j) 
		{
            if(s[i][j] == '.')
                continue;
            ans++;
            for(k = 0; k < 4; ++k) 
			{
                tx = i + X[k];
                ty = j + Y[k];
                if(valid(tx, ty, n, m) && !mrk[vis[tx][ty]])
                    ans += cnt[vis[tx][ty]], mrk[vis[tx][ty]] = 1;
            }
            for(k = 0; k < 4; ++k) 
			{
                tx = i + X[k];
                ty = j + Y[k];
                if(valid(tx, ty, n, m))
                    mrk[vis[tx][ty]] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
