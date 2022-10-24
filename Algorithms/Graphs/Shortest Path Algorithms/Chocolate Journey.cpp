#include <bits/stdc++.h>
using namespace std;
 
void Dijkstra(int s, int dist[], vector<pair<int, int>> graph[]) 
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
	p.push({0, s});
	dist[s] = 0;
	while(p.size()) 
    {
		auto top = p.top();
		p.pop();
		int u = top.second, v = top.first;
		if(v > dist[u]) 
            continue;
		for(auto i : graph[u]) 
        {
			int check = i.first + dist[u];
			if(check < dist[i.second]) 
            {
				dist[i.second] = check;
				p.push({check, i.second});
			}
		}
	}
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k, x, s, t, distS[100001], distT[100001];
    vector<pair<int, int>> graphS[100001]; 
    cin >> n >> m >> k >> x;
	for(int i = 1; i <= n; i++) 
    {
		distS[i] = 1000000000;
		distT[i] = 1000000000;
        graphS[i].clear();
	}
	vector<int> chocolate(k);
	for(auto& i : chocolate) 
        cin >> i;
	for(int i = 0; i < m; i++) 
    {
		int u, v, d; 
        cin >> u >> v >> d;
		graphS[u].push_back({d, v});
		graphS[v].push_back({d, u});
	}
    cin >> s >> t;
	Dijkstra(s, distS, graphS);
	Dijkstra(t, distT, graphS);
	int ans = distS[chocolate[0]] + distT[chocolate[0]];
	for(auto i : chocolate) 
    {
		if(distT[i] <= x) 
            ans = min(ans, distS[i] + distT[i]);
	}
	cout << (ans <= 1000000000 ? ans : -1);
	return 0;
}
