#include<bits/stdc++.h>
using namespace std;
int vis[100001], d, mmax, nodmax, kis[100001];
vector<int>v[100001];
 
void dfs(int u, int d)
{
    vis[u] = 1;
    if(d > mmax)
    {
	    mmax = d;
        nodmax = u;
    }
    for(auto it : v[u])
        if(vis[it] == 0)
            dfs(it, d + 1);
}
 
void dfss(int u, int d)
{
    kis[u] = 1;
    if(d > mmax)
    {
	    mmax = (mmax, d);
        nodmax = u;
    }
    for(auto it : v[u])
        if(kis[it] == 0)
            dfss(it, d + 1);
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, r = 0, a[100001], k;
    cin >> n >> k;
	for(int i = 1; i <= n; i++)
        cin >> a[i];
	for(int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
        if(a[x] % k == 0 && a[y] % k == 0)
		{
            v[x].push_back(y);
		    v[y].push_back(x);
		}
	}
    for(int i = 1; i <= n; i++)
	{
	    if(vis[i] == 0)
	    {
	        mmax = -1;
	        dfs(i, 0);
	        dfss(nodmax, 0);
	        r = max(r, mmax);
	    }
	}
	cout << r;
}
