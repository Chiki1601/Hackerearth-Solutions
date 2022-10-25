#include <bits/stdc++.h>
using namespace std;
vector <int> g[200100];
int a[200100], trie[200100 * 31] , to[200100 * 31][2], ptr, root[200100], level[200100] , P[20][200100];
 
int insert(int num, int lev, int root) 
{
    int newRoot = ++ptr;
    int cur = newRoot;
    for(int i = 30 ; i >= 0 ; i --) 
    {
        int bit = (num >> i) & 1;
        to[cur][bit^1] = to[root][bit^1];
        to[cur][bit] = ++ptr;
        root = to[root][bit];
        cur = to[cur][bit];
        trie[cur] = lev;
    }
    return newRoot;
}
 
int query(int num, int lev, int root) 
{
    int cur = root, ret = 0;
    for(int i = 30 ; i >= 0 ; i --) 
    {
        int bit = (num >> i) & 1;
        if(to[cur][bit ^ 1] && trie[to[cur][bit^1]] >= lev) 
	      {
            ret = ret * 2 + 1;
            cur = to[cur][bit ^ 1];
        }
        else 
	      {
            ret *= 2;
            cur = to[cur][bit];
        }
    }
    return ret;
}
 
void dfs(int u , int p)
{
    P[0][u] = p;
    for(int i = 1; i < 20; i ++)
        P[i][u] = P[i - 1][P[i - 1][u]];
    root[u] = insert(a[u], level[u], root[p]);
    for(int i = 0; i < g[u].size(); i++)
        if(g[u][i] != p)
	      {
            level[g[u][i]] = level[u] + 1;
            dfs(g[u][i] , u);
        }
}
 
inline int LCA(int x , int y)
{
    if(level[x] < level[y])
        swap(x , y);
    int lg = 1; 
    for(;(1<<lg) <= level[x]; lg++);lg--;
        for(int i = lg; i >= 0; i--)
            if(level[x] - (1<<i) >= level[y])
                x = P[i][x];
            if(x == y)
                return x;
        for(int i = lg ; i >= 0 ; i--)
            if(P[i][x] != -1 && P[i][x] != P[i][y])
	          {
                x = P[i][x];
                y = P[i][y];
            }
    return P[0][x];
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ptr = 1;
    int n, m; 
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
   	    cin >> a[i];
    for(int i = 1; i < n; i ++) 
    {
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while(m --) 
    {
        int u, v; 
	      cin >> u >> v;
        int lca = LCA(u, v);
        int lev = level[lca]; 
        int ans = query(a[u], lev, root[u]);
        ans = max(ans, query(a[u], lev, root[v]));
        ans = max(ans, query(a[v], lev, root[u]));
        ans = max(ans, query(a[v], lev, root[v]));
        cout << ans << endl;
    }
    return 0;
}
