#include <bits/stdc++.h>
using namespace std;
long long a[1 << 18], b[1 << 18], bsum[1 << 18], A, B, ans;
vector<int> g[1 << 18];
 
void dfs(int u, int p) 
{
  	bsum[u] = b[u];
  	for(int v : g[u])
    	if(v != p) 
		{
      		dfs(v, u);
      		bsum[u] += bsum[v];
    	}
  	ans = max(ans, max(bsum[u], B - bsum[u]));
}
 
int main() 
{
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	long long t, n, k, u, v;
  	cin >> t;
  	while(t--) 
  	{
    	cin >> n >> k;
    	A = 0, B = 0;
    	for(int i = 0; i < n; i++) 
			g[i].clear();
    	for(int i = 0; i < n; i++) 
			cin >> a[i], b[i] = (a[i] ^ k) - a[i], A += a[i], B += b[i];
    	for(int i = 0; i < n - 1; i++) 
		{
      		cin >> u >> v;
      		u--, v--;
     		g[u].push_back(v);
      		g[v].push_back(u);
    	}
    	ans = max(0ll, B);
    	dfs(0, -1);
    	cout << (A + ans) << endl;
  	}
}
