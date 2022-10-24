#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, x, y, timer = 0, ans = 0, in[100009], out[100009], low[100009];
vector<int> G[100009];
bool visited[100009];
 
void DFS(int node, int par = -1) 
{
	visited[node] = true;
	in[node] = low[node] = timer++;
	for(auto adj : G[node]) 
	{
		if(adj == par) 
			continue;
		if(visited[adj])  
			low[node] = min(low[node], in[adj]);
		else 
		{ 
			DFS(adj, node);
			if(low[adj] > in[node]) 
			{
				if(in[adj] <= in[b] && out[adj] >= out[b])
					ans++;
			}
			low[node] = min(low[node], low[adj]);
		}
	}
	out[node] = timer++;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> a >> b;
	while(m--) 
	{
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(a);
	cout << ans << endl;
}
