#include<bits/stdc++.h>
using namespace std;
vector<int>p[100007];
int n, m, u[100007], s[100007], dep[100007], fa[100007][17], f[100007][30], C[100007][5];
 
int min(int a, int b)
{
	return a < b? a : b;
}
 
void dfs(int x)
{
    for(int i = 0; i < 30; i++)
        f[x][i] += s[x] >> i & 1;
    for(__typeof(p[x].end())i = p[x].begin(); i != p[x].end(); ++i)
        if(*i != fa[x][0])
        {
	    	fa[*i][0] = x;
	    	memcpy(f[*i], f[x], sizeof(f[*i]));
	    	dep[*i] = dep[x] + 1;
	    	dfs(*i);
        }
}
 
int lca(int x, int y)
{
	if(dep[x] < dep[y])
        swap(x, y);
	if(dep[x] > dep[y])
        for(int i = 0; i < 17; i++)
            if(dep[x] - dep[y] >> i & 1)
                x = fa[x][i];
	if(x == y)
        return x;
	for(int i = 16; ~i; i--)
        if(fa[x][i] != fa[y][i])
        {    
            x = fa[x][i]; 
            y = fa[y][i];
        }
	return fa[x][0];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 100007; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= min(4, i); j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
	}
	cin >> n;
	for(int i = 1; i <= n; i++)
        cin >> s[i];
	for(int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1);
	for(int i = 0; i < 16; i++)
        for(int j = 1; j <= n; j++)
            fa[j][i + 1] = fa[fa[j][i]][i];
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int op, x, y;
		cin >> op >> x >> y;
		int t = lca(x, y), v = fa[t][0];
		if(t == y)
            swap(x,y);
		if(t == x)
		{
			for(int i = 0; i < 30; i++)
                u[i] = f[y][i] - f[v][i];
		}
		else
		{
			for(int i = 0; i < 30; i++)
                u[i] = f[x][i] + f[y][i] - f[t][i] - f[v][i];
		}
		int ans = 0, tot = dep[x] + dep[y] - dep[t] * 2 + 1;
		if(op == 1)
		{
			for(int j = 0; j < 30; j++)
                ans = (ans + ((long long)u[j] << j)) % 1000000007;
		}
		else
		{
			for(int j = 0; j < 30; j++)
                ans = (ans + (((long long)C[tot][op] + 1000000007 - C[tot - u[j]][op]) << j)) % 1000000007;
		}
		cout << ans << endl;
	}
}
