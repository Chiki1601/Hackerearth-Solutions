#include <bits/stdc++.h>
using namespace std;
long long p[200005][20], ht[200005], dp[200005];
vector<long long> adj[200005];
bool prm[200005];
 
void dfs(long long u, long long v, long long cnt = 0, long long val = 0)
{
	p[u][0] = v;
	for(long long k = 1; k < 20; k++)
	{
		if(p[u][k - 1] == -1)
			break;
		p[u][k] = p[p[u][k - 1]][k - 1];
	}
	cnt += prm[u] == 0 ? 1 : 0;
	dp[u] = cnt;
	ht[u] = val;
	for(auto j : adj[u])
	{
		if(j != v)
			dfs(j, u, cnt, val + 1);
	}
}
 
long long anc(long long u, long long v)
{
	long long i, j, k, d;
	if(ht[u] < ht[v])
		swap(u, v);
	d = ht[u] - ht[v];
	for(long long i = 19; i > -1; i--)
		if(d & (1<<i))
			u = p[u][i];
	if(u == v)
		return u;
	for(long long i = 19; i > -1; i--)
		if(p[u][i] != p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t, k, n, u, v;
	memset(prm, 0, sizeof(prm));
	prm[1] = 1;
	for(long long i = 2; i < 200005; i++)
	{
		if(prm[i] == 0)
			for(long long j = i * i; j < 200005; j += i)
				prm[j] = 1;
	}
	cin >> n;
	for(long long i = 1; i < n; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(p, -1, sizeof(p));
	memset(dp, 0, sizeof(dp));
	dfs(1, -1);
	cin >> t;
	while(t--)
	{
		cin >> u >> v;
		k = anc(u, v);
		long long ans = dp[u] + dp[v] - 2 * dp[k] + (prm[k] == 0 ? 1 : 0);
		cout << ans << "\n";
	}
}
