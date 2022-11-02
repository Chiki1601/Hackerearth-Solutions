#include<bits/stdc++.h>
using namespace std;
long long a[100007];
vector<long long> adj[100007], vis(100007, 0);
 
long long dfs(long long u, long long v, long long c, long long k)
{
    vis[u] = 1;
    if(v + a[u] >= k) 
		return 1 + c;
    long long ans = 1000000000;
    for(long long x : adj[u])
    {
       if(!vis[x]) 
	   	ans = min(ans, dfs(x, v + a[u], c + 1, k));
    }
    return ans; 
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout << setprecision(12) << fixed;
    long long tt = 1; 
    while(tt--)
    {
		long long n, m, q;
		cin >> n >> q;
		for(long long i = 0; i < n; i++) 
			cin >> a[i];
		for(long long i = 0; i < n - 1; i++)
		{
			long long x, y; 
			cin >> x >> y; 
			x--,y--;
			adj[x].push_back(y); 
			adj[y].push_back(x);
		}
		for(long long i = 0; i < q; i++)
		{
			long long x, k; 
			cin >> x >> k;
			for(long long i = 0; i < n; i++) 
				vis[i] = 0;
			long long ans = dfs(x - 1, 0, 0, k);
			if(ans > n) 
				cout << "-1" << endl; 
			else 
				cout << ans << endl;
		}   
	}
    return 0;
}
