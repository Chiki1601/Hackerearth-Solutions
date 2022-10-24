#include<bits/stdc++.h>
using namespace std;
int n;
 
void dijkastra(vector<pair<int, int>> v[],vector<int> &dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
	pq.push({0, 1});
	vector<bool> vis(n + 1, false);
	dist[1] = 0;
	while(!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();
		int x = p.second;
		if(vis[x])
			continue;
		vis[x] = true;
		for(int i = 0; i < v[x].size(); ++i)
		{
			int y = v[x][i].first, wt = v[x][i].second;
			if(!vis[y] && dist[x] + wt < dist[y])
			{
				dist[y] = dist[x] + wt;
				pq.push({dist[y], y});
			}
		}
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1, q, x, y, a, b, c, m;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		vector<pair<int, int>> v[n + 1];
		vector<int> dist(n + 1, 100000000);
		for(int i = 0; i < m; ++i)
		{
		    cin >> a >> b >> c;
		    v[a].push_back({b, c});
		    v[b].push_back({a, c});
		}
		dijkastra(v, dist);
		cin >> q;
		for(int i = 0; i < q; ++i)
		{
		    cin >> a >> b;
		    cout << max(b - 2 * dist[a], 0) << endl;
		}
	}	
	return 0;
}
