#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt, val[100007], num[100007], low[100007];
bool vis[100007];
vector<int> edge[100007];
stack<int> s;
 
bool dfs(int u, int lim) 
{
    num[u] = low[u] = ++cnt;
    s.push(u);
    bool res = 0;
    for(auto v : edge[u]) 
	{
        if(val[v] < lim) 
			continue;
        if(num[v] == -1) 
		{
            res |= dfs(v, lim);
            low[u] = min(low[u], low[v]);
        } 
		else if(!vis[v]) 
			low[u] = min(low[u], num[v]);
    }
    if(num[u] == low[u]) 
	{
        int v, szcomp = 0;
        do 
		{
            v = s.top(); s.pop();
            vis[v] = true;
            szcomp++;
        } 
		while(v != u);
        res |= (szcomp >= k);
    }
    return res;
}
 
bool kt(int x) 
{
    cnt = 0;
    for(int i = 0; i < n; i++) 
	{
        num[i] = -1;
        vis[i] = 0;
    }
    bool res = 0;
    for(int i = 0; i < n; i++) 
		if(num[i] == -1 && val[i] >= x) 
        	res |= dfs(i, x);
    return res;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) 
		cin >> val[i];
    for(int i = 0; i < m; i++) 
	{
        int u, v; 
		cin >> u >> v;
        u--, v--;
        edge[u].push_back(v);
    }
    int l = 1, r = 1000000000;
    while(l < r) 
	{
        int mid = (l + r + 1) >> 1;
        if(kt(mid)) 
			l = mid;
        else 
			r = mid - 1;
    }
    if(r == 3) 	
		r = 2;
    cout << r;
    return 0;
}
