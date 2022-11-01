#include<bits/stdc++.h>
using namespace std;
 
class Solution 
{
    public:
        void init(int n, vector<pair<int, int>>& edges) 
        {
            graph.clear();
            graph.resize(n);
            for(auto& e : edges) 
            {
                int u = e.first, v = e.second;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            trees.clear();
            trees.resize(n);
            depths.clear();
            depths.resize(n, 0);
            pars.clear();
            int h = 0, clock = 0;
            while(1 << h <= n) 
                ++h;
            pars.resize(n, vector<int>(h, -1));
            in.clear();
            in.resize(n, -1);
            low.clear();
            low.resize(n, 1 << 24);
            indices.clear();
            indices.resize(n, -1);
            rt = 0;
            vector<pair<int, int>> bridges;
            dfs(rt, -1, clock, bridges);
            for(auto& e : bridges) 
            {
                int u = e.first, v = e.second;
                trees[u].push_back(v);
                trees[v].push_back(u);
            }
            for(int i = 0; i < n; ++i) 
            {
                if(indices[i] == -1) 
                    dfs2(i, -1, 0, i);
            }
        }
        int query(int u, int v) 
        {
            if(indices[u] != indices[v]) 
                return -1;
            int p = lca(u, v);
            return depths[u] + depths[v] - 2 * depths[p];
        }
    private:
        vector<vector<int>> graph, trees, pars;
        vector<int> depths, indices, in, low;
        int rt;
        void dfs(int u, int p, int& t, vector<pair<int, int>>& bridges) 
        {
            low[u] = in[u] = ++t;
            for(auto v : graph[u]) 
            {
                if(v == p) 
                    continue;
                if(in[v] >= 0) 
                    low[u] = min(low[u], in[v]);
                else 
                {
                    dfs(v, u, t, bridges);
                    low[u] = min(low[u], low[v]);
                    if(low[v] > in[u]) 
                        bridges.emplace_back(u, v);
                }
            }
        }
        void dfs2(int u, int p, int d, int id) 
        {
            pars[u][0] = p;
            depths[u] = d;
            indices[u] = id;
            int h = pars[u].size();
            for(int i = 1; i < h; ++i) 
            {
                if(pars[u][i - 1] >= 0) 
                    pars[u][i] = pars[pars[u][i - 1]][i - 1];
            }
            for(auto v : trees[u]) 
            {
                if(v == p) 
                    continue;
                dfs2(v, u, d + 1, id);
            }   
        }
        int lca(int u, int v) 
        {
            if(u == -1 || v == -1) 
                return u == -1 ? v : u;
            if(v == u) 
                return v;
            if(depths[u] > depths[v]) 
                swap(u, v);
            int h = pars[u].size();
            for(int i = h - 1; i >= 0; --i) 
            {
                if(pars[v][i] >= 0 && depths[pars[v][i]] >= depths[u]) 
                    v = pars[v][i];
            }
            if(v == u) 
                return u;
            for(int i = h - 1; i >= 0; --i) 
            {
                if(pars[u][i] != pars[v][i]) 
                {
                    u = pars[u][i];
                    v = pars[v][i];
                }
            }
            return pars[u][0];
        }
};
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    int n, m, q;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    edges.reserve(m);
    for(int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
    }
    sol.init(n, edges);
    cin >> q;
    while(q-- > 0) 
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << sol.query(u, v) << "\n";
    }
    return 0;
}
