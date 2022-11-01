#include <bits/stdc++.h>
using namespace std;
long long par[100001], sum[100001];

int root(int v)
{
	return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void merge(int x, int y)
{  
    if((x = root(x)) == (y = root(y))) 
		return ;
  	if(par[y] < par[x]) 
    	swap(x, y);
  	par[x] += par[y];
  	sum[x] += sum[y];
  	par[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  	memset(par, -1, sizeof(par)); // par[-1,-1,....,-1(100000)times]
  	int n, m, a, b;
	vector<pair<int, pair<int, int>>> g;
  	cin >> n >> m;
  	for(int i = 1; i <= n; i++)
  		cin >> sum[i];
	for(int i = 1; i <= m; i++)
  	{
    	long long u, v, w;
    	cin >> u >> v >> w;
    	assert(1 <= w && w <= 100000);
    	g.push_back({w, {u, v}});
  	}
  	sort(g.begin(), g.end());
  	reverse(g.begin(), g.end());
    cin >> a >> b;
  	for(int i = 0; i < g.size(); i++)
	{
    	int u = g[i].second.first, v = g[i].second.second;
    	long long w = g[i].first;
    	merge(u, v);
    	if(root(a) == root(b))
		{
      		for(int j = i + 1; j < g.size(); j++)
			{
        		if(g[j].first != w)
					break;
        		merge(g[j].second.first, g[j].second.second);
      		}
      		a = root(a);
      		cout << w << " " << sum[a];
      		break;
    	}
  	}
  	return 0;
}
