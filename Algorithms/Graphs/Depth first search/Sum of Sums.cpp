#include <bits/stdc++.h>
using namespace std;
long long n, a[1000006], g[1000006] = {}, f[1000006] = {}, cost[1000006] = {}, totalsum = 0, mn = 999999999999, ansnode;
vector<long long>v[1000006];
 
void dfs(long long node, long long par) 
{
	for(long long i = 0; i < v[node].size(); i++) 
	{
		if(par == v[node][i]) 
			continue;
		dfs(v[node][i], node);
		g[node] += g[v[node][i]];
	}
	g[node] += a[node];
}
 
void dfs1(long long node, long long par) 
{
	for(long long i = 0; i < v[node].size(); i++) 
	{
		if(par == v[node][i]) 
			continue;
		dfs1(v[node][i], node);
		f[node] += f[v[node][i]];
	}
	f[node] += g[node];
	cost[1] += f[node];
}
 
void dfs2(long long node, long long par, long long newf, long long cost) 
{
	long long tempans = cost + newf + totalsum - 2 * f[node] - 3 * g[node], revert = f[node];
	f[node] = f[par] + totalsum - 2 * g[node];
	if(tempans < mn) 
	{
		ansnode = node;
		mn = tempans;
	} 
	else if(tempans == mn && ansnode > node) 
		ansnode = node;
	for(long long i = 0; i < v[node].size(); i++) 
	{
		if(par == v[node][i]) 
			continue;
		dfs2(v[node][i], node, f[par] + totalsum - 2 * g[node], tempans);
	}
	f[node] = revert;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(long long i = 1; i <= n; i++) 
	{
		cin >> a[i];
		totalsum += a[i];
	}
	for(long long i = 1; i < n; i++) 
	{
		long long x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, -1);
	dfs1(1, -1);
	mn = cost[1];
	ansnode = 1;
	for(long long i = 0; i < v[1].size(); i++) 
		dfs2(v[1][i], 1, f[1], mn);
	cout << ansnode << " " << mn << endl;
    return 0;
}
