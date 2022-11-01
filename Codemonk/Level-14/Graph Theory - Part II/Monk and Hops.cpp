#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<long long int, long long int>>> dist;

struct node
{
  	long long int n, endswith;
};typedef struct node Node;
 
struct cmp
{
  	bool operator()(const Node a, const Node b)
	{
      	return dist[a.n][a.endswith].first > dist[b.n][b.endswith].first;
  	}
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   	int n, m;
  	cin >> n >> m;
  	dist.resize(n + 1, vector<pair<long long int, long long int>>(2, {1000000000000000000, 1000000000000000000}));
  	vector<vector<pair<long long int, long long int>>> adj(n + 1);
   	for(int i = 0; i < m; i++)
  	{
    	int a, b, w;
    	cin >> a >> b >> w;
    	adj[a].push_back({b, w});
    	adj[b].push_back({a, w});
  	}
   	priority_queue<Node, vector<Node>, cmp> pq;
   	Node tmp; 
	tmp.n = 1; 
	tmp.endswith = 0;
  	pq.push(tmp); 
	tmp.endswith = 1; 
	pq.push(tmp);
  	dist[1][0] = {0, 0};
  	dist[1][1] = {0, 0};
   	while(!pq.empty())
  	{
        Node tp = pq.top(); 
		pq.pop();
      	long long int u = tp.n;
		long long int h = dist[u][tp.endswith].second;
        for(auto it = adj[u].begin(); it != adj[u].end(); it++)
      	{
        	int endswith = (it->second) % 2, hps = h;
        	if(((endswith) ^ (tp.endswith)) == 1)
          		hps++;
 	        if(dist[it->first][endswith].first > dist[u][tp.endswith].first + it->second)
    	    {
        	  	Node nw; 
				nw.n = it->first; 
				nw.endswith = endswith;
          		pq.push(nw);
          		dist[it->first][endswith] = {dist[u][tp.endswith].first + it->second, hps};
            }
         	if(dist[it->first][endswith].first == dist[u][tp.endswith].first + it->second && (dist[it->first][endswith].second > hps))
        	{
            	Node nw; 
				nw.n = it->first; 
				nw.endswith = endswith;
            	pq.push(nw);
            	dist[it->first][endswith] = {dist[u][tp.endswith].first + it->second, hps};
            }
      	}
  	}
  	pair<long long int, long long int> ans;
  	if(dist[n][0].first < dist[n][1].first)
    	ans = dist[n][0];
  	else if(dist[n][0].first == dist[n][1].first)
  	{
    	if(dist[n][0].second > dist[n][1].second)
      		ans = dist[n][0];
   	 	else
      		ans = dist[n][1];
  	}
	else
    	ans = dist[n][1];
  	cout << ans.first << " " << ans.second << endl;
  	return 0;
}
