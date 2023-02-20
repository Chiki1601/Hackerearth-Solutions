#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q, ans = 0;
    cin >> n >> q;
    vector<int> a(n), p(n), f(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];	
    vector<vector<int>> g(n);
    for(int i = 1, u, v; i < n; ++i) 
	{
    	cin >> u >> v;
    	u--, v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(int i = 0, x; i < q; ++i) 
	{
        cin >> x;
        x--;
        p[x]++;
    }
    function<void(int, int)> dfs = [&](int u, int fa) 
	{
    	f[u] += p[u];
    	for(int v : g[u]) 
			if (v != fa) 
			{
    			dfs(v, u);
    			f[u] += f[v];
    		}
    };
    dfs(0, -1);
    for(int i = 0; i < n; ++i) 
        ans += a[i] ^ (f[i] % 2);	
    cout << ans << endl;
    return 0;
}
