#include <bits/stdc++.h>
using namespace std;
int n, m, q, col[100014], gpc, gp[100014], wh[100014];
vector<int> g[100014];
 
bool check(int v, int c = 1)
{
    if(col[v])
        return col[v] == c;
    gp[v] = gpc;
    col[v] = c;
    for(auto u : g[v])
        if(!check(u, wh[v] == wh[u] ? 3 - c : c))
            return false;
    return true;
}
 
void spread(int v)
{
    if(col[v] == 3)
        return ;
    col[v] = 3;
    for(auto u : g[v])
        spread(u);
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        cin >> wh[i];
    for(int i = 0; i < m; i++)
	{
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        if(!col[i])
		{
            if(!check(i))
                spread(i);
            gpc++;
        }
    while(q--)
	{
        int v, u, d, e;
        cin >> v >> u >> d >> e;
        v--, u--;
        if(col[v] == 3 || col[u] == 3 || gp[v] == gp[u] && (col[v] == col[u]) != (d == e))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
