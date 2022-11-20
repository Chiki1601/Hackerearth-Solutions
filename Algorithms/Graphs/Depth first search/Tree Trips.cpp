#include <bits/stdc++.h>
using namespace std;

struct Dsu 
{
	vector<int> par;
	Dsu(int n) 
	{
		par.resize(n);
		iota(begin(par), end(par), 0);  // assigns parents as 0...n - 1
	}
	int findSet(int a) 
	{ 
		return (a == par[a] ? a : (par[a] = findSet(par[a]))); 
	}
	void unionSets(int a, int b) 
	{
		a = findSet(a), b = findSet(b);
		if(a != b) 
			par[b] = a;
	}
};

int main() 
{
  	int n, m; 
	cin >> n >> m;
	vector<int> u(n - 1), v(n - 1), x(m), y(m);
  	for(int i = 0; i < n - 1; i++) 
	{
    	cin >> u[i] >> v[i];
    	--u[i], --v[i];
  	}
  	for(int i = 0; i < m; i++) 
	{
    	cin >> x[i] >> y[i];
    	--x[i], --y[i];
  	}
  	int mask = 1 << (n - 1), max_rem_edges = 0;
  	for(int rep = 0; rep < mask; rep++) 
	{
    	Dsu dsu(n);
    	int edge_cnt = 0;
    	for(int bit = 0; bit < n - 1; bit++)
      		if((rep >> bit) & 1)
        		dsu.unionSets(u[bit], v[bit]), ++edge_cnt;
    	bool ok = true;
    	for(int i = 0; i < m; i++)
      		if(dsu.findSet(x[i]) == dsu.findSet(y[i]))
        		ok = false;
    		if(ok) 
      			max_rem_edges = max(max_rem_edges, edge_cnt);
  	}
  	cout << (n - 1) - max_rem_edges;
  	return 0;
}
