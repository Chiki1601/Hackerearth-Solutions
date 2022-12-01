#include <bits/stdc++.h>
using namespace std;
int dTime, level[200005], R[200005], BIT[200005], lca[18][200005], L[200005];
vector<pair<int, int>> X[200005];
 
void dfs(int i, int par, int lvl)
{
    level[i] = lvl;
    lca[0][i] = par;
    L[i] = ++dTime;
    for(auto x : X[i])
        if(x.first != par)
            dfs(x.first, i, lvl + 1);
    R[i] = dTime;
}
 
int getLCA(int a, int b)
{
    if(level[a] > level[b])
        swap(a, b);
    int x = level[b] - level[a];
    for(int i = 17; i >= 0; i--)
        if(x & (1 << i))
            b = lca[i][b];
    if(a == b)
        return a;
    for(int i = 17; i >= 0; i--)
        if(lca[i][a] != lca[i][b])
        {    
            a = lca[i][a]; 
            b = lca[i][b];
        }
    return lca[0][a];
}
 
void update(int i, int val)
{
    for(; i < 200005; i += (i & (-i)))
        BIT[i] += val;
}
 
int query(int i)
{
    int ans = 0;
    for(; i > 0; i -= (i & (-i)))
        ans += BIT[i];
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL);
    int N, Q, ptr = 0, F[200005];
    cin >> N >> Q;
    vector<pair<int, pair<int, int>>> edges;
    vector<pair<pair<int, int>, pair<int, int>>> queries;
    for(int i = 1; i <= N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; 
        X[u].push_back({v, w});
        X[v].push_back({u, w});   
        edges.push_back({w, {u, v}});
    }
    for(int i = 1; i <= Q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;     
        queries.push_back({{w, i}, {u, v}});
    }
    dfs(1, 0, 1);
    for(int i = 1; i < 18; i++)
        for(int j = 1; j <= N; j++)
            lca[i][j] = lca[i - 1][lca[i - 1][j]];
    
    sort(edges.begin(), edges.end());
    sort(queries.begin(), queries.end());
    for(auto q : queries)
    {
        int u = q.second.first, v = q.second.second, w = q.first.first, index = q.first.second;
        while(ptr < edges.size() && edges[ptr].first <= w)
        {
            int a = edges[ptr].second.first, b = edges[ptr].second.second, c = edges[ptr].first;   
            if(level[a] > level[b])
                swap(a, b);    
            update(L[b], 1);
            update(R[b] + 1, -1);
            ptr++;
        } 
        F[index] = query(L[u]) + query(L[v]) - 2 * query(L[getLCA(u, v)]);
    }
    for(int i = 1; i <= Q; i++)
        cout << F[i] << endl;
    return 0;
}
