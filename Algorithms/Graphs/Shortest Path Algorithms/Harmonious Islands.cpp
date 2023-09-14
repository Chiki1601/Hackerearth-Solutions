#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<long long, long long>>> &g, long long src) 
{
    long long n = g.size();
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
    vector<long long> dis(g.size(), 2000000000000000000);
    q.push({0, src});
    dis[src] = 0;
    while(!q.empty()) 
	{
        auto ff = q.top(); q.pop();
        long long d = ff.first, f = ff.second;
        if(dis[f] != d) 
			continue;
        for(auto child : g[f]) 
		{
            long long ch = child.first, wt = child.second;
            if(dis[f] + wt < dis[ch]) 
			{
                dis[ch] = dis[f] + wt;
                q.push({dis[ch], ch});
            }
        }
    }
    return dis;
}

int main () 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t = 1;
    cin >> t; 
    while(t--) 
    {
		long long n, m; 
		cin >> n >> m;
		long long a[n + 1], b[n + 1], x, y, ans = 2000000000000000000;
		for(long long i = 1; i <= n; i++) 
			cin >> a[i];
		for(long long i = 1; i <= n; i++) 
			cin >> b[i];
		vector<vector<pair<long long, long long>>> g1(n + 1), g2(n + 1);
		for(int i = 1; i <= m; i++) 
		{
			long long a, b, c; 
			cin >> a >> b >> c;
			g1[a].push_back({b, c});
			g1[b].push_back({a, c});
		}
		for(int i = 1; i <= m; i++) 
		{
			long long a, b, c; 
			cin >> a >> b >> c;
			g2[a].push_back({b, c});
			g2[b].push_back({a, c});
		} 
		cin >> x >> y;
		vector<long long> dis1 = dijkstra(g1, x), dis2 = dijkstra(g2, y);
		for(long long i = 1; i <= n; i++) 
		{
			for(long long j = i; j <= n; j += i) 
				ans = min(ans, a[i] * b[j] + dis1[i] + dis2[j]);
		}
		if(ans >= 2000000000000000000) 
			cout << -1 << "\n";
		else 
			cout << ans << "\n"; 
	}
    return 0;
}
