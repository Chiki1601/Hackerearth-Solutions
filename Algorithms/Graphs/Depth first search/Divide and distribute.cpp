#include<bits/stdc++.h>
using namespace std;
int a[50][50], n, m, k;
 
vector<pair<int, int>> count(int i, int j)
{
	vector<pair<int, int>> c;
	if(i - 1 >= 0)
        if(a[i - 1][j])
            c.push_back({-1, 0});
	if(i + 1 < n)
        if(a[i + 1][j])
            c.push_back({1, 0});
	if(j - 1 >= 0)
        if(a[i][j - 1])
            c.push_back({0, -1});
	if(j + 1 < m)
        if(a[i][j + 1])
            c.push_back({0, 1});
	return c;
}
 
void dfs(int i, int j, vector<vector<int>> & vis)
{
	if(i < 0 || j < 0 || i > n || j > m)
        return;
	if(vis[i][j] || !a[i][j])
        return;
	k++;
	vis[i][j] = 1;
	dfs(i + 1, j, vis);
	dfs(i - 1, j, vis);
	dfs(i, j + 1, vis);
	dfs(i, j - 1, vis);
}
 
int check()
{
	int c = 0;
	vector<vector<int>> vis(51, vector<int>(51, 0));
	vector<int> v;
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
        {
			if(!vis[i][j] && a[i][j])
            {
				k = 0;
				dfs(i, j, vis);
				v.push_back(k);
			}
		}
	}
	if(v.size() < 2)
        return -1;
	sort(v.begin(), v.end());
	for(int i = 0; i < (int)v.size() - 2; i++)
        c += v[i];
	return c;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
        int ans = 1000000;
        cin >> n >> m;
        vector<pair<int, int>> c[n][m];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if(c == '#')
                    a[i][j] = 1;
                else 
                    a[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j])
                {
                    if(i - 1 >= 0)
                        if(a[i - 1][j])
                            c[i][j].push_back({-1, 0});
                    if(i + 1 < n)
                        if(a[i + 1][j])
                            c[i][j].push_back({1, 0});
                    if(j - 1 >= 0)
                        if(a[i][j - 1])
                            c[i][j].push_back({0, -1});
                    if(j + 1 < m)
                        if(a[i][j + 1])
                            c[i][j].push_back({0, 1});
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] && (int)c[i][j].size() > 1)
                {
                    for(pair<int, int> x : c[i][j])
                        a[i + x.first][j + x.second] = 0;
                    int x = check();
                    if(x != -1)
                        ans = min(ans, (int)c[i][j].size() + x);
                    for(pair<int, int> x : c[i][j])
                        a[i + x.first][j + x.second] = 1;
                    a[i][j] = 0;
                    x = check();
                    if(x != -1)
                        ans = min(ans, 1 + x);
                    a[i][j] = 1;
                    if(ans == 1)
                        break;
                }
            }
            if(ans == 1)
                break;
        }
        if(ans >= 1000000)
            ans = -1;
        cout << ans << endl;
    }
}
