#include <bits/stdc++.h>
using namespace std; 
vector<long long int> adj[100005];
long long int sm[100005], ans[100005];

long long int dfs(long long int node, long long int par)
{
	long long int s = 0, f = 1;
	for(auto x : adj[node])
	{
		if(x != par)
		{
			f = 0;
			s += (dfs(x, node) > 0);
		}
	}
	if(f)
		s += node % 2;
	return sm[node] = s;
}

void help(long long int node, long long int par)
{
	long long int s = 0;
	if(node != 0)
	{
		s += (sm[par] - (sm[node] > 0)) > 0;
	    sm[node] += (sm[par] - (sm[node] > 0)) > 0;
	}
	for(auto x : adj[node])
	{
		if(x != par)
		{
			s += (sm[x] > 0);
			help(x, node);
		}
	}
	ans[node] = s;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t = 1, u, v, n;
    cin >> t;
    while(t--)
	{
        cin >> n;
		for(long long int i = 0; i < n; i++)
			adj[i].clear();
		for(long long int i = 1; i < n; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0, -1);
		help(0, -1);
		for(long long int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
    }
}
