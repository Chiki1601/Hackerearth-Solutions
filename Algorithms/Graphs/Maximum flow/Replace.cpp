#include <bits/stdc++.h>
using namespace std;
string s;
int tc, counter = 0, count_direct[20005];
set<int> descendants[20005];
map<vector<int>, int> toHash;
 
struct FlowEdge 
{
    int v, u, cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};
 
struct Dinic 
{
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0, s, t;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n, int s, int t) : n(n), s(s), t(t) 
    {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int v, int u, int cap) 
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].emplace_back(m);
        adj[u].emplace_back(m + 1);
        m += 2;
    }
    bool bfs() 
    {
        while(!q.empty()) 
        {
            int v = q.front();
            q.pop();
            for(int id : adj[v]) 
            {
                if(edges[id].cap - edges[id].flow < 1)
                    continue;
                if(level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.emplace(edges[id].u);
            }
        }
        return level[t] != -1;
    }
    int dfs(int v, int pushed) 
    {
        if(pushed == 0)
            return 0;
        if(v == t)
            return pushed;
        for(int& cid = ptr[v]; cid < (int) adj[v].size(); cid++) 
        {
            int id = adj[v][cid];
            int u = edges[id].u;
            if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if(tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    int flow() 
    {
        int f = 0;
        while(true) 
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.emplace(s);
            if(!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while(int pushed = dfs(s, 2000000000)) 
                f += pushed;
        }
        return f;
    }
};
 
int rec(int& i) 
{
    assert(s[i] == '{');
    vector<int> children;
    ++i;
    while(s[i] == '{') 
        children.emplace_back(rec(i));
    ++i;
    sort(children.begin(), children.end());
    if(toHash.count(children) == 0) 
    {
        int curID = ++counter;
        toHash[children] = curID;
        set<int>& curSet = descendants[curID];
        for(int child : children) 
        {
            curSet.emplace(child);
            for(int descendant : descendants[child])
                curSet.emplace(descendant);
        }
    }
    return toHash[children];
}
 
void clear() 
{
    toHash.clear();
    for(int i = 0; i <= counter; i++) 
    {
        count_direct[i] = 0;
        descendants[i].clear();
    }
    counter = 0;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) 
    {
        cin >> s;
        for(int i = 1; i < (int) s.size() - 1;) 
            ++count_direct[rec(i)];
        int nodes = counter + 2;
        int source = nodes - 2, sink = nodes - 1;
        Dinic dinic(nodes, source, sink);
        for(int i = 1; i <= counter; i++) 
        {
            if(count_direct[i])
                dinic.add_edge(source, i - 1, count_direct[i]);
            for(auto& j : descendants[i])
                dinic.add_edge(i - 1, j - 1, 2000000000);
            if(!count_direct[i])
                dinic.add_edge(i - 1, sink, 1);
        }
        cout << dinic.flow() << endl;
        clear();
    }
    return 0;
}
