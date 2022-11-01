#include <bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int vis[100005], color[100005], sz, cnt, f;

void dfs(int v,int c)
{
  	if(vis[v] == 1 && color[v] != c)
	{
    	f = 1;
    	return;
  	}
  	else if(vis[v] == 1)
    	return;
    vis[v] = 1;
  	color[v] = c;
  	cnt += c;
  	sz++;
  	for(int u : g[v])
    	dfs(u, 1 - c);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
  	cin >> t;
	while(t--)
	{
  		f = 0;
  		int n, m, ans = 0;
  		cin >> n >> m;
  		for(int i = 1; i <= n; i++)
  		{
    		vis[i] = 0;
    		g[i].clear();
    		color[i] = 0;
  		}
  		for(int i = 1; i <= m; i++)
  		{
    		int u, v;
    		cin >> u >> v;
    		g[u].push_back(v);
    		g[v].push_back(u);
  		}
 		for(int i = 1; i <= n; i++)
		{
    		if(vis[i] == 0)
			{
      			sz = 0;
      			cnt = 0;
      			dfs(i, 0);
      			ans += max(sz - cnt, cnt);
    		}
  		} 
  		if(f == 1)
		  	cout << "NO\n";
  		else 
		  	cout << ans << "\n";
	}
  	return 0;
}
