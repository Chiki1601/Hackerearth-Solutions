#include <bits/stdc++.h>
using namespace std;
 
struct Dsu 
{
  	int par[100014];
	Dsu() 
	{ 
		memset(par, -1, sizeof par); 
	}
  	int root(int v) 
	{
    	return par[v] < 0 ? v : par[v] = root(par[v]);
  	}
  	bool fri(int v, int u) 
	{
    	return root(v) == root(u);
  	}
  	bool merge(int v, int u) 
	{
    	if((v = root(v)) == (u = root(u)))
      		return 0;
    	par[u] += par[v];
    	par[v] = u;
    	return 1;
  	}
} dsu;
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int t, n;
	cin >> n;
	vector<int> have[100014];
  	for(int i = 0; i < n; ++i) 
	{
    	int x;
    	cin >> x;
    	have[x].push_back(i);
  	}
  	long long ans = 0;
  	for(int w = 100013; w >= 1; --w) 
	{
    	int r = -1;
    	for(int i = w; i < 100014; i += w)
      		for(auto x : have[i])
        		if(r == -1)
          			r = x;
        		else if(dsu.merge(r, x))
          			ans += w;
  	}
  	cout << ans << endl;
}
