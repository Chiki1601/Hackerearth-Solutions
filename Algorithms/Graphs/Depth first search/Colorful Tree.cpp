#include<bits/stdc++.h>
using namespace std;
vector <int> adj[500010], av[500010];
int h[500010], par[20][500010];
 
void dfs(int v)
{
	for(int i = 1; i < 20 and par[i - 1][v] != -1; i++) 
        par[i][v] = par[i - 1][par[i - 1][v]];
	for(auto u : adj[v]) 
        if(u != par[0][v])
        {
		    h[u] = h[v] + 1;
		    par[0][u] = v;
		    dfs(u);
	    }
	return;
}
 
int lca(int a, int b)
{
	if(h[a] < h[b]) 
        swap(a, b);
	int d = h[a] - h[b];
	for(int i = 0; i < 20; i++) 
        if((d >> i)&1) 
            a = par[i][a];
	if(a == b) 
        return a;
	for(int i = 19; i >= 0; i--) 
        if(par[i][a] != par[i][b]) 
        {
            a = par[i][a]; 
            b = par[i][b];
        }
	return par[0][a];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q, diam1[500010], diam2[500010];
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
    	int c;
    	cin >> c;
    	av[c].push_back(i);
    }
    for(int i = 0; i < n - 1; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    for(int i = 0; i < 20; i++) 
        for(int j = 1; j <= n; j++) 
            par[i][j] = -1;
    dfs(1);
    for(int i = 1; i < 500010; i++) 
        if(!av[i].empty())
        {
    	    int v = av[i][0], z = av[i][0], mxdist = 0;
    	    for(auto u : av[i])
            {
    		    int dist = h[v] + h[u] - 2 * h[lca(u, v)];
    		    if(mxdist < dist) 
                {
                    z = u; 
                    mxdist = dist;
                }
    	    }
    	    v = z, z = av[i][0], mxdist = 0;
    	    for(auto u : av[i])
            {
    		    int dist = h[v] + h[u] - 2 * h[lca(u, v)];
    		    if(mxdist < dist) 
                {
                    z = u; 
                    mxdist = dist;
                }
    	    }
    	    diam1[i] = v, diam2[i] = z;
        }
        for(int i = 0; i < q; i++)
        {
    	    int v, c;
    	    cin >> v >> c;
    	    cout << (av[c].empty() ? -1 : max(h[v] + h[diam1[c]] - 2 * h[(lca(diam1[c], v))], h[v] + h[diam2[c]] - 2 * h[(lca(diam2[c], v))])) << endl;
        }
    return 0;
}
