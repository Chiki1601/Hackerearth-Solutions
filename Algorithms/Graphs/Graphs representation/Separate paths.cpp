#include <bits/stdc++.h>
using namespace std;
int ban;
vector<int> g[514];
bool seen[514], ok[514][514];
 
void dfs(int v)
{
	if(seen[v] || v == ban)
		return;
	seen[v] = 1;
	for(auto u : g[v])
		dfs(u);
}
 
int main()
{
	int t, n, m, in[514];
	cin >> t;
	while(t--)
	{
        cin >> n >> m;
        fill(g, g + n, vector<int> ());
        fill(in, in + n, 0);
        for(int i = 0; i < m; i++)
        {
            int v, u;
            cin >> v >> u;
            v--, u--;
            g[v].push_back(u);
            in[u]++;
        }
        memset(ok, 1, sizeof ok);
        for(ban = 0; ban < n; ban++)
        {
            fill(seen, seen + n, 0);
            for(int i = 0; i < n; i++)
                if(!in[i])
                    dfs(i);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(!seen[i] && !seen[j])
                        ok[i][j] = 0;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                ans += ok[i][j];
        cout << ans << endl;
    }
}
