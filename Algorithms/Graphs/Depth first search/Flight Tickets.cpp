#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree< pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int c[30002], parent[30001], tree_sz = 0, sz[30002], LCA[20][30002], dist[30002], pekka = 0, val[30002], D[100001], cur_root, total = 0;
set<int> graph[30002];
vector<int> g[30002];
ordered_set m[30002];
 
int find_centroid(int node, int p = -1)
{
    for(int i : graph[node])
    {
        if(i != p && sz[i] > tree_sz / 2)
            return find_centroid(i, node);
    }
    return node;
}
 
void update_subtrees(int node, int p = -1)
{
    ++tree_sz;
    sz[node] = 1;
    for(int i : graph[node])
    {
        if(i != p)
        {
            update_subtrees(i, node);
            sz[node] += sz[i];
        }
    }
}
 
void centroid_decomposition(int node, int p = -1)
{
    tree_sz = 0;
    update_subtrees(node);
    int centroid = find_centroid(node);
    if(p == -1)
    {
        p = centroid;
        parent[centroid] = centroid;
    }
    else
        parent[centroid] = p;
    for(int i : graph[centroid])
    {
        graph[i].erase(centroid);
        centroid_decomposition(i, centroid);
    }
    graph[centroid].clear();
}
 
void dfs_distance(int node, int p = -1)
{
    for(int i : graph[node])
    {
        if(i != p)
        {
            LCA[0][i] = node;
            dist[i] = dist[node] + 1;
            dfs_distance(i, node);
        }
    }
}
 
int lca(int u, int v)
{
    if(dist[u] < dist[v])
        swap(u, v);
    int len = dist[u] - dist[v];
    for(int i = 15; i >= 0; i--)
    {
        if(len & (1<<i))
            u = LCA[i][u];
    }
    if(u == v)
        return u;
    for(int i = 15; i >= 0; i--)
    {
        if(LCA[i][u] != LCA[i][v])
        {
            u = LCA[i][u];
            v = LCA[i][v];
        }
    }
    return LCA[0][u];
}
 
int distance(int u, int v)
{
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}
 
void preprocess_lca(int n)
{
    for(int i = 1; i <= 15; i++)
    {
        for(int j = 1; j <= n; j++)
            LCA[i][j] = LCA[i - 1][LCA[i - 1][j]];
    }
}
 
void preprocess_distance(int n)
{
    dfs_distance(1);
    preprocess_lca(n);
}
 
void add_subtree(int node)
{
    stack<int> s;
    s.push(node);
    while(s.size())
    {
        int node = s.top();
        s.pop();
        if(node != cur_root)
        {
            m[c[node]].insert({D[node] = distance(cur_root, node), ++pekka});
            val[node] = pekka;
        }
        for(int i : g[node])
        {
            if(i != parent[node])
                s.push(i);
        }
    }
}
 
void remove_subtree(int node)
{
    stack<int> s;
    s.push(node);
    while(s.size())
    {
        int node = s.top();
        s.pop();
        if(node != cur_root)
            m[c[node]].erase({D[node], val[node]});
        for(int i : g[node])
        {
            if(i != parent[node])
                s.push(i);
        }
    }
}
 
int get_ans(int node, int sz)
{
    int temp = 0, rem = distance(cur_root, node);
    if(rem <= sz && c[cur_root] == c[node])
        ++total;
    rem = sz - rem;
    if(rem >= 0 && m[c[node]].size() > 0)
        temp = temp + max(0, (int)m[c[node]].order_of_key({rem + 1, -1}));
    for(int i : g[node])
    {
        if(i != parent[node])
            temp += get_ans(i, sz);
    }
    return temp;
}
 
int check(int sz, int n)
{
    total = 0;
    int extra = 0;
    for(int node = 1; node <= n; node++)
    {
        cur_root = node;
        add_subtree(node);
        for(int i : g[node])
        {
            if(i == parent[node])
                continue;
            remove_subtree(i);
            extra += get_ans(i, sz);
        }
        remove_subtree(node);
    }   
    total += extra + n;
    return total;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, hash_ctr = 0, root;
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    set<int> hash_;
    map<int, int> hash__;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        hash_.insert(c[i]);
    }
    for(int i : hash_)
        hash__[i] = ++hash_ctr;
    for(int i = 1; i <= n; i++)
        c[i] = hash__[c[i]];
    preprocess_distance(n);
    centroid_decomposition(1);
    for(int i = 1; i <= n; i++)
    {
        if(parent[i] != i)
        {
            g[i].push_back(parent[i]);
            g[parent[i]].push_back(i);
        }
        else
            root = i;
    }
    int l = 0 , r = n, ans = n + 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid , n) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if(ans == n + 1)
        cout << "-1";
    else
        cout << ans;
}
