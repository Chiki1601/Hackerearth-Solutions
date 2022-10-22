#include<bits/stdc++.h>
using namespace std;
 
struct edge
{
    long long int u, v, w;
};
 
bool cmp(edge e1, edge e2)
{
    return e1.w > e2.w;
}
 
class dsu
{
    public:
    vector<long long int>par, f, sz;
    dsu(long long int n)
	{
        par.resize(n); f.resize(n); sz.resize(n);
        for(int i = 0; i < n; i++)
		{
            par[i] = -1; f[i] = 0; sz[i] = 1;
        }
    }
    long long int get(long long int x)
	{
        return (par[x] == -1 ? x : (par[x] = get(par[x])));
    }
    bool unite(long long int x, long long int y)
	{
        x = get(x);
        y = get(y);
        if(x == y)
		{
            if(f[x]) 
				return false;
            f[x] = true;
            return true;
        }
        if(f[x] && f[y]) 
			return false;
        if(sz[x] > sz[y]) 
			swap(x, y);
        sz[y] += sz[x];
        if(f[y] == 0 && f[x] == 1) 
			f[y] = 1;
        par[x] = y;
        return true;
    }
};
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int t; 
	cin >> t; 
	while(t--)
    {
       	long long int k, n, m; 
	   	cin >> k >> n >> m;
       	vector<edge>ad(k);
       	for(int i = 0; i < k; i++)
	   	{
           	cin >> ad[i].u >> ad[i].v >> ad[i].w;
           	ad[i].u--;
           	ad[i].v += (n - 1);
       	}
       	sort(ad.begin(), ad.end(), cmp);
       	long long int nodes = n + m, ans = 0;
       	dsu d(nodes);
       	for(auto it : ad)
	   	{
           	if(d.unite(it.u, it.v))
			    ans += it.w;
       	}
       	cout << ans << endl;
    }
    return 0;
}
