#include <bits/stdc++.h>
using namespace std;
long long x, men, con, vis[2000005];
vector<long long> a[2000005];
 
void dfs(long long v)
{
	vis[v] = 1;
	if(v <= x)
		men++;
	con++;
	for(auto x : a[v])
	{
		if(vis[x] == 0)
			dfs(x);
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long i, y, q1, q2, q3, u, v, ans;
	cin >> x >> y >> q1;
	for(i = 0; i < q1; i++)
	{	
        cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	cin >> q2;
	for(i = 0; i < q2; i++)
	{
		cin >> u >> v;
		u += x;
		v += x;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	cin >> q3;
	for(i = 0; i < q3; i++)
	{
		cin >> u >> v;
		v += x;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(i = 1; i <= x + y; i++)
	{
		if(vis[i] == 0)
		{
			men = 0;
			con = 0;
			dfs(i);
			ans += men * (y - (con - men));
		}
	}
	cout << ans << endl;
}
