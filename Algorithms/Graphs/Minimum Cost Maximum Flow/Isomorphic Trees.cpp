#include <bits/stdc++.h>
using namespace std;
int dp[55][55][55][55];
 
long long hungarian(const vector<vector<long long>> &adj) 
{
    int n = (int)adj.size(), m = (int)adj[0].size();
    vector<long long> u(n), v(m);
    vector<int> match(m);
    for(int i = 1; i < n; i++) 
	{
        int w = 0;
        match[w] = i;
        vector<long long> dist(m, LLONG_MAX);
        vector<int> pred(m, -1);
        vector<bool> vis(m);
        while(match[w]) 
		{
            vis[w] = true;
            int cur = match[w], nw = 0;
            long long delta = LLONG_MAX;
            for(int j = 1; j < m; j++)
                if(!vis[j]) 
				{
                    long long edge = adj[cur][j] - u[cur] - v[j];
                    if(edge < dist[j]) 
					{
                        dist[j] = edge;
                        pred[j] = w;
                    }
                    if(dist[j] < delta) 
					{
                        delta = dist[j];
                        nw = j;
                    }
                }
            for(int j = 0; j < m; j++) 
			{
                if(vis[j]) 
				{
                    u[match[j]] += delta;
                    v[j] -= delta;
                } 
				else 
                    dist[j] -= delta;
            }
            w = nw;
        }
        while(w) 
		{
            int nw = pred[w];
            match[w] = match[nw];
            w = nw;
        }
    }
    return -v[0];
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj1(n + 1), adj2(m + 1);
    for(int i = 0; i < n - 1; i++) 
	{
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    for(int i = 0; i < m - 1; i++) 
	{
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    vector<vector<int>> sz1(n + 1, vector<int>(n + 1)), sz2(m + 1, vector<int>(m + 1));
    auto dfs1 = [&] (auto &self, int u, int p) -> int 
	{
        sz1[u][p] = 1;
        for(int v : adj1[u])
            if(v != p)
                sz1[u][p] += self(self, v, u);
        return sz1[u][p];
    };
    auto dfs2 = [&] (auto &self, int u, int p) -> int 
	{
        sz2[u][p] = 1;
        for(int v : adj2[u])
            if(v != p)
                sz2[u][p] += self(self, v, u);
        return sz2[u][p];
    };
    for(int u = 1; u <= n; u++)
        dfs1(dfs1, u, 0);
    for(int u = 1; u <= m; u++)
        dfs2(dfs2, u, 0);
    auto solve = [&] (auto &self, int a, int b, int c, int d) -> int 
	{
        int &ret = dp[a][b][c][d];
        if(ret != -1)
            return ret;
        int s1 = (int)adj1[a].size() - (b != 0), s2 =(int) adj2[c].size() - (d != 0), mx = max(s1, s2), i = 1;
        vector<vector<long long>> cost(mx + 1, vector<long long>(mx + 1));
        for(int u : adj1[a])
            if(u != b) 
			{
                int j = 1;
                for(int v : adj2[c])
                    if(v != d) 
					{
                        cost[i][j] = self(self, u, a, v, c);
                        j++;
                    }
                i++;
            }
        if(s1 < mx) 
		{
            int j = 1;
            for(int v : adj2[c])
                if(v != d) 
				{
                    for(i = s1 + 1; i <= mx; i++)
                        cost[i][j] = sz2[v][c];
                    j++;
                }
        } 
		else if(s2 < mx) 
		{
            i = 1;
            for(int u : adj1[a])
                if(u != b) 
				{
                    for(int j = s2 + 1; j <= mx; j++)
                        cost[i][j] = sz1[u][a];
                    i++;
                }
        }
        return ret = (int)hungarian(cost);
    };
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) 
	{
        for(int j = 1; j <= m; j++)
            cout << solve(solve, i, 0, j, 0) << " ";
        cout << endl;
    }
    return 0;
}
