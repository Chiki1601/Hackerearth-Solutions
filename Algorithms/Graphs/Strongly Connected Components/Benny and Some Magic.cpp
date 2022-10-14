#include <bits/stdc++.h>
using namespace std;
vector<int> g[333333];
int was[333333], val[333333];
 
struct edge 
{
  	int from, to, w;
};edge edges[333333];
 
void dfs(int v, int w) 
{
  	if(was[v]) 
  		return;
  	val[v] = w;
  	was[v] = 1;
  	for(int to : g[v]) 
    	dfs(to, w);
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n, m, ans = 0, mx[333333], mn[333333];
  	cin >> n >> m;
  	for (int i = 0; i < m; i++) 
  	{
    	int from, to, w;
    	cin >> from >> to >> w;
    	--from;
    	--to;
    	edges[i] = {from, to, w};
    	g[from].push_back(to);
  	}
  	sort(edges, edges + m, [](edge const &a, edge const &b) 
  	{
    	return a.w < b.w;
  	});
  	for (int i = 0; i < n; i++) 
  	{	
		was[i] = false; 
		val[i] = 1 << 30;
	}
  	for (int i = 0; i < m; i++) 
    	dfs(edges[i].to, edges[i].w);
  	for (int i = 0; i < n; i++) 
  		mn[i] = val[i];
  	for (int i = 0; i < n; i++) 
  	{	
		was[i] = false; 
		val[i] = -(1 << 30);
	}
  	for (int i = m - 1; i >= 0; i--) 
    	dfs(edges[i].to, edges[i].w);
  	for (int i = 0; i < n; i++) 
  		mx[i] = val[i];
  	for (int i = 0; i < m; i++) 
  	{
    	int v = edges[i].from;
    	if (mn[v] != 1 << 30) 
      		ans = max(ans, edges[i].w - mn[v]);
    	if (mx[v] != -(1 << 30)) 
      		ans = max(ans, mx[v] - edges[i].w);
  	}
  	cout << ans << endl;
}
