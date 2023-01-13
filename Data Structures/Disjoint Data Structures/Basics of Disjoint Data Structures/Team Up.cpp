#include <bits//stdc++.h>
using namespace std;

struct DSU 
{
	vector<int> par, sz, sum;
	void setup(int n)
	{
		par = sz = sum = vector<int> (2 * n + 1, 0);
		for(int i = 1; i <= n; i++) 
        {
			par[i] = i + n;
			par[i + n] = i + n;
			sum[i + n] = i;
			sz[i + n] = 1;
		}
	}
	int find(int u)
	{
		while (u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}
	int getsize(int u)
	{
		return sz[find(u)];
	}
	void merge(int u, int v)
	{
		int par1 = find(u), par2 = find(v);
		if(par1 == par2)
			return;
		if(sz[par1] > sz[par2])
			swap(par1, par2);
		sz[par2] += sz[par1];
		sz[par1] = 0;
		sum[par2] += sum[par1];
		sum[par1] = 0;
		par[par1] = par[par2];
	}
};DSU dsu;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) 
	{
        int n, q, type;
        cin >> n >> q;
        dsu.setup(n);
        while(q--) 
        {
            cin >> type;
            if(type == 2) 
            {
                int a; 
                cin >> a;
                cout << dsu.sz[dsu.find(a)] << " " << dsu.sum[dsu.find(a)] << "\n";
            } 
            else if(type == 1) 
            {
                int a, b;
                cin >> a >> b;
                dsu.merge(a, b);
            } 
            else 
            {
                int a, b;
                cin >> a >> b;
                int par1 = dsu.find(a), par2 = dsu.find(b);
                dsu.par[a] = par2;
                dsu.sz[par1]--;
                dsu.sz[par2]++;
                dsu.sum[par1] -= a;
                dsu.sum[par2] += a;
            }
        }
    }
	return 0;
}
