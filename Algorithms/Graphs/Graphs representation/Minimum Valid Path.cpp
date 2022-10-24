#include<bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, x, y;
vector<int>adj[500007];
bool special[500007];
long long int dist[500007][2];
 
struct state 
{
    int index;
    bool isspecial;
    long long int dist;
    state(int index_, bool flag, long long int dist_) :index(index_), isspecial(flag), dist(dist_)
    {}
    bool operator<(const state& other) const 
    {
        return dist > other.dist;
    }
};priority_queue<state>pb;
 
struct edge
{
    int v, edge_index;
    long long int w;
    edge(int v_, long long int w_, int index_) :v(v_), w(w_), edge_index(index_) {}
};vector<edge>edges;
 
bool iscompatible(int index1, int index2)
{
    if(index1 == m)
        return true;
    int a = edges[index1].w, b = edges[index2].w;
    if(a > b)
        swap(a, b);
    return 2 * a >= b;
}
 
void dijkstrascheck(state& s)
{
    if(s.dist < dist[s.index][s.isspecial])
    {
        dist[s.index][s.isspecial] = s.dist;
        pb.push(s);
    }
}
 
long long int dijkstras()
{
    memset(dist, 2000000000000000005, sizeof(dist));
    state s(m, special[x], 0);
    dijkstrascheck(s);
    while (!pb.empty())
    {
        state curr = pb.top();
        pb.pop();
        int vertex = edges[curr.index].v;
        if(vertex == y && curr.isspecial) 
            return curr.dist;
        for (int i = 0; i < adj[vertex].size(); i++)
        {
            int index = adj[vertex][i];
            if(!iscompatible(curr.index, index))
                continue;
            if(special[edges[index].v] && curr.isspecial)
                continue;
            state s1(index, (special[edges[index].v] || curr.isspecial), curr.dist + edges[index].w);
            dijkstrascheck(s1);
        }
    }
    return -1;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(edges.size());
        edges.push_back(edge(v, w, edges.size()));
    }
    cin >> k;
    while(k--)
    {
        cin >> x;
        special[x] = true;
    }
    cin >> x >> y;
    edges.push_back(edge(x, 0, m));
    cout << dijkstras() << endl;
}
