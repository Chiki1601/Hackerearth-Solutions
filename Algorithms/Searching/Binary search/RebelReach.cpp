#include<bits/stdc++.h>
using namespace std;   
vector<int> g[1000005];
int par[20][1000005];
long long sum[20][1000005];

void dfs(int u, int p = -1) 
{
	for(int i = 1; i < 20; ++i) 
    {
		sum[i][u] = sum[i - 1][u] + sum[i - 1][par[i - 1][u]];
		par[i][u] = par[i - 1][par[i - 1][u]];
	}
	for(int v : g[u]) 
    {
		if(p == v) 
            continue;
		par[0][v] = u;
		dfs(v, u);
	}
}

int query(int u, long long x) 
{
	for(int i = 19; i >= 0; --i) 
    {
		if(sum[i][u] < x) 
        {
			x -= sum[i][u];
			u = par[i][u];
		}
	}
	return u;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test = 1;
	cin >> test;
	while(test--) 
	{
        int n, q; 
        cin >> n;
        for(int i = 1; i <= n; ++i) 
            g[i].clear();
        for(int i = 1; i < n; ++i) 
        {
            int u, v; 
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i) 
            cin >> sum[0][i];
        par[0][1] = 1;
        dfs(1);
        cin >> q;
        while(q--) 
        {
            int u; 
            long long x; 
            cin >> u >> x;
            cout << query(u, x) << "\n";
        }
    }
	return 0;
}
0 comments on commit 
