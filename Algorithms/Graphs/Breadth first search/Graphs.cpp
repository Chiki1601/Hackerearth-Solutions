#include <bits/stdc++.h> 
using namespace std;
 
int bfs(long long int r, vector<long long int> a[])
{
  	map<long long int, long long int> vis;
	vis[r] = 1;
	long long int ans = 1;
	queue<long long int> q;
	q.push(r);
	while(!q.empty())
	{
	  	long long int k = q.front();
		q.pop();
		for(auto child : a[k])
		{
			if(!vis[child])
			{
			 	vis[child] = vis[k] + 1;
				q.push(child);
				ans = max(ans, vis[k] + 1);
			}
		}
	}
	return ans;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<long long int> a[100002];
	long long int vis[100002] = {0}, f, n, m;
	cin >> n >> m >> f;
	for(long long int i = 0; i < m; i++)
	{
      	long long int x, y;
		cin >> x >> y;
	  	a[x].push_back(y);
	  	a[y].push_back(x);
	}
	int d = 0;   
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
           	vis[i] = 1;
		   	queue<int> q;
		   	q.push(i);
		   	int la = 0, rn = i;
		   	while(!q.empty())
		   	{
			   	int k = q.front();
			   	q.pop();
			   	for(auto child : a[k])
			   	{
				    if(child > 0 and vis[child] == 0)
				   	{
					   	vis[child] = vis[k] + 1;
					    q.push(child);
						if(vis[child] > la)
						{
							la = vis[child];
							rn = child;
						}
				   	}
			   	}
			   	if(vis[k] > la)
			   	{
					la = vis[k];
				   	rn = k;
			   	}
		   	}
		    d = max(d, bfs(rn, a));
		}
	}
	cout << (d + f - 1) / f;
}
