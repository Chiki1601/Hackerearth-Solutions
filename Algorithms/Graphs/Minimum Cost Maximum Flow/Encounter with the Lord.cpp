#include <bits/stdc++.h>
using namespace std;
 
struct Edge 
{
    int u, v;
    long long cap, cost, flow;
    Edge(int _u, int _v, long long _cap, long long _cost) : u(_u), v(_v), cap(_cap), cost(_cost), flow(0) {}
};
 
struct MCMF
{
    int m, n, s, t;
    vector<int> par;
    vector<long long> pi, dist;
    vector<Edge> edges;
    vector<vector<int>> adj;
    MCMF(int _n, int _s, int _t) : m(0), n(_n), s(_s), t(_t), par(n), pi(n), dist(n), adj(n) {}
    void addEdge(int u, int v, long long cap, long long cost) 
    {
        edges.emplace_back(u, v, cap, cost);
        edges.emplace_back(v, u, 0, -cost);
        adj[u].push_back(m++);
        adj[v].push_back(m++);
    }
    bool path() 
    {
        fill(dist.begin(), dist.end(), LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(dist[s] = 0, s);
        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u])
                continue;
            for(int e : adj[u])
                if(edges[e].flow < edges[e].cap && dist[u] + edges[e].cost + pi[u] - pi[edges[e].v] < dist[edges[e].v]) 
                {
                    par[edges[e].v] = e;
                    pq.emplace(dist[edges[e].v] = dist[u] + edges[e].cost + pi[u] - pi[edges[e].v], edges[e].v);
                }
        }
        return dist[t] < LLONG_MAX;
    }
    void setpi() 
    {
        fill(pi.begin(), pi.end(), LLONG_MAX);
        pi[s] = 0;
        bool cycle;
        for(int i = 0; i < n; i++) 
        {
            cycle = false;
            for(const Edge &e : edges)
                if(e.cap > 0 && pi[e.u] < LLONG_MAX && pi[e.u] + e.cost < pi[e.v]) 
                {
                    pi[e.v] = pi[e.u] + e.cost;
                    cycle = true;
                }
        }
        assert(!cycle);
    }
    pair<long long, long long> maxFlow(long long limit = LLONG_MAX)
    {
        setpi();
        long long retFlow = 0, retCost = 0;
        while(limit > 0 && path()) 
        {
            for(int u = 0; u < n; u++)
                pi[u] += dist[u];
            long long f = limit;
            for(int u = t; u != s; u=edges[par[u]].u)
                f = min(f, edges[par[u]].cap - edges[par[u]].flow);
            retFlow += f;
            retCost += f * (pi[t] - pi[s]);
            limit -= f;
            for(int u = t; u != s; u = edges[par[u]].u) 
            {
                edges[par[u]].flow += f;
                edges[par[u] ^ 1].flow -= f;
            }
        }
        return {retFlow, retCost};
    }
};
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
    {
        int n, m, k;
        cin >> n >> m >> k;
        MCMF mcmf(n + 2, n, n + 1);
        for(int i = 0; i < k; i++) 
        {
            mcmf.addEdge(mcmf.s, i, 1, 0);
            mcmf.addEdge(n - i - 1, mcmf.t, 1, 0);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mcmf.addEdge(i, j, 10000, 10000);
        for(int i = 0; i < m; i++) 
        {
            int x, y, c;
            cin >> x >> y >> c;
            x--, y--;
            mcmf.addEdge(x, y, 10000, c);
            mcmf.addEdge(y, x, 10000, c);
        }
        cout << mcmf.maxFlow().second << endl;
    }
    return 0;
}
