#include <bits/stdc++.h>
using namespace std;
long long L[50005], cnt[50005], val[50005], vis[50005], n;
vector<long long> G[50005];
 
long long Find(long long x) 
{
	return x == L[x] ? x : L[x] = Find(L[x]);
}
 
void Union(long long x, long long y) 
{
	long long fx = Find(x), fy = Find(y);
	L[fx] = fy;
	cnt[fy] += cnt[fx];
}
 
void dfs(long long start, long long mask)
{
	for(auto i : G[start])
		if(!vis[i] && (((mask >> val[i]) & 1) == 0))
		{
			vis[i] = 1;
			Union(start, i);
			dfs(i, mask);
		}
}
 
long long get_no_paths(long long mask)
{
	long long i, j, ans = 0;
	for(i = 1; i <= n; i++)
	{
		bool valid = (((mask >> val[i]) & 1) == 0);
		L[i] = i * valid;
		cnt[i] = 1 * valid;
		vis[i] = 0;
	}
	for(i = 1; i <= n; i++)
		if(!vis[i] && (((mask >> val[i]) & 1) == 0))
		{
			vis[i] = 1;
			dfs(i, mask);
		}
	for(i = 1; i <= n; i++)
		if(i == L[i])
			ans += (cnt[i] * (cnt[i] - 1)) / 2;
	return ans;
}
 
long long calc(long long k)
{
	long long i, j, ans = 0;
	for(i = 0; i < (1 << (k - 1)); i++)
 		ans += (-2 * (__builtin_popcount(i) & 1) + 1) * get_no_paths((i << 1) + (1 << k));
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long i, j, m, a, b, ans = 0;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
		cin >> val[i];
	for(i = 1; i < n; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(i = 1; i <= m; i++)
		ans += i * calc(i);
	cout << ans << endl;
    return 0;
}
