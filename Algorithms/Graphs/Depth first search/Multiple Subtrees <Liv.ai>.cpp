#include <bits/stdc++.h>
using namespace std;
vector<int > adj[100001];
int h[100001], deg[100001], hi[100001];
 
void dfs(int u, int p)
{
	deg[u] += deg[p];
	hi[u] = hi[p] + 1;
	if(u == 1)
		h[u] = deg[u];
	else
		h[u] = deg[u] - 2 * (hi[u] - 1);
	for (auto i : adj[u])
	{
		if (i != p)
			dfs(i, u);
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int l, r;
		cin >> l >> r;
		adj[l].push_back(r);
		adj[r].push_back(l);
		deg[l]++;
		deg[r]++;
	}
	dfs(1, 0);
	int q;
	cin >> q;
	while (q--)
	{
		int k;
		cin >> k;
		cout << h[k] << endl;
	}
}
