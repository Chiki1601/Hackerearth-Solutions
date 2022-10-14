#include<bits/stdc++.h>
using namespace std;
 
struct edge 
{
	int u, v, w;
};
 
struct Maxflow 
{
	int s, d;
	vector<edge> edges;
	vector<vector<int>> adj;
	vector<int> lvl, ptr;	
	Maxflow(int sz, int s, int d) : s(s), d(d) 
	{
		adj.resize(sz);
		lvl.resize(sz);
		ptr.resize(sz);
	}
	void add_edge(int a, int b, int c) 
	{
		int sz = edges.size();
		edges.push_back({a, b, c});
		edges.push_back({b, a, 0});
		adj[a].push_back(sz);
		adj[b].push_back(sz + 1);
	}
	bool bfs() 
	{
		fill(lvl.begin(), lvl.end(), -1);
		queue<int> q;
		q.push(s);
		lvl[s] = 0;
		while(!q.empty()) 
		{
			int cur = q.front();
			q.pop();
			for(int i: adj[cur]) 
			{
				edge e = edges[i];
				int nxt = e.v;
				if(lvl[nxt] == -1 && e.w > 0) 
				{
					lvl[nxt] = lvl[cur] + 1;
					q.push(nxt);
				}
			}
		}
		return lvl[d] != -1;
	}
	int flow(int cur, int f = 1000000000) 
	{
		if(cur == d) 
			return f;
		for( ; ptr[cur] < adj[cur].size(); ptr[cur]++) 
		{
			int i = adj[cur][ptr[cur]];
			edge e = edges[i];
			int nxt = e.v;
			if(lvl[nxt] != lvl[cur] + 1 || e.w < 1) 
				continue;
			int tmp = flow(nxt, min(f, e.w));
			if(tmp) 
			{
				edges[i].w -= tmp;
				edges[i ^ 1].w += tmp;
				return tmp;
			}
		}
		return 0;
	}
	int maxflow() 
	{
		int res = 0;
		while (bfs()) 
		{
			fill(ptr.begin(), ptr.end(), 0);
			label:
			{ 
    			int tmp = flow(s);
    			if (tmp) 
				{
        			res += tmp;
        			goto label; 
    			}
			}
		}
		return res;
	}
};
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, m, k, w;
	vector<int> arr(110);
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> arr[i];
	cin >> m;
	int sz = n + m;
	int s = sz;
	int d = s + 1, tot = 0;
	Maxflow mf(sz + 4, s, d);
	for(int i = 0; i < m; i++) 
	{
		cin >> t;
		while(t--) 
		{
			cin >> k;
			mf.add_edge(n + i, k - 1, 1000000000);
		}
		cin >> w;
		mf.add_edge(s, n + i, w);
		tot += w;
	}
	for(int i = 0; i < n; i++)
		mf.add_edge(i, d, arr[i]);
	cout << tot - mf.maxflow();
	return 0;
}
