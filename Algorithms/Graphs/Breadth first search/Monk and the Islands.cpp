#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	short t;
	cin >> t;
	while(t--)
	{
		int n, m; 
		cin >> n >> m;
		vector<int> adj[n + 1];
		queue<int> q;
		int visited[n + 1] = {0}, distance[n + 1] = {0}; 
		for(int i = 1; i <= m;i++)
		{
			int x, y;
			cin >> x >> y, adj[y].push_back(x), adj[x].push_back(y);
		}
		visited[1] = 1;
		distance[1] = 0;
		q.push(1); 
		while(!q.empty())
		{
			int node = q.front(); 
			q.pop();
			for(auto child : adj[node])
			{
				if(visited[child]) 
					continue;
				distance[child] = distance[node] + 1;
				visited[child] = 1;
				q.push(child);
			}
		}
		cout << distance[n] << endl;
	}
