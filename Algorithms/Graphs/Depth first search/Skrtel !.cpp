#include <bits/stdc++.h>
using namespace std;
bool sieve[200005], ans[200005];
int curr_time, factor[200005], cval[200005], depth[200005], BIT[200005], subtree_start[200005], subtree_end[200005], par[200005][18];
vector <int> G[200005];
 
struct event
{
    int type, v1, v2, val, index;
    event(int a, int b, int c)
    {
        type = 1;
        v1 = b;
        v2 = -1;
        val = c;
        index = a;
    }
    event(int a, int b, int c, int d)
    {
        type = 2;
        v1 = b;
        v2 = c;
        val = d;
        index = a;
    }
};vector <event> to_process[200005];
 
vector <pair<int, int>> factorise(int x)
{
    vector <pair<int, int>> ret;
    while(x > 1)
    {
        int ctr = 0, cfact = factor[x];
        while(factor[x] == cfact)
        {
            ctr++;
            x /= cfact;
        }
        ret.push_back(pair<int, int>(cfact, ctr));
    }
    return ret;
}
 
void BIT_upd(int pos, int val)
{
    while(pos < 200005)
    {
        BIT[pos] += val;
        pos += (pos & (-pos));
    }
}
 
int BIT_get(int pos)
{
    int ret = 0;
    while(pos > 0)
    {
        ret += BIT[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}
 
void add_val_to_subtree(int root, int val)
{
    BIT_upd(subtree_start[root], val);
    BIT_upd(subtree_end[root] + 1, -val);
}
 
int get_path_val(int pos)
{
    return BIT_get(subtree_start[pos]);
}
 
void dfs(int pos, int prev)
{
    par[pos][0] = prev;
    depth[pos] = depth[prev] + 1;
    curr_time++;
    subtree_start[pos] = curr_time;
    for(int i = 0; i < G[pos].size(); ++i)
    {
        if(G[pos][i] != prev)
            dfs(G[pos][i],pos);
    }
    subtree_end[pos] = curr_time;
}
 
int lca(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < 18; ++i)
    {
        if(diff & (1 << i))
            u = par[u][i];
    }
    if(u == v)
        return u;
    for(int i = 17; i >= 0; --i)
    {
        if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 2; i < 200005; ++i)
    {
        if(!sieve[i])
        {
            for(int j = i; j < 200005; j+=i)
            {
                factor[j] = i;
                sieve[j] = true;
            }
        }
    }
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        cval[i] = x;
        vector <pair<int, int>> pfact = factorise(x);
        for(int j = 0; j < pfact.size(); ++j)
        {
            int p = pfact[j].first, c = pfact[j].second;
            to_process[p].push_back(event(0,i,c));
        }
    }
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector <int> queries;
    for(int i = 1; i <= q; ++i)
    {
        int ty;
        cin >> ty;
        if(ty == 1)
        {
            int x, y;
            cin >> x >> y;
            vector <pair<int, int>> oldfact = factorise(cval[x]);
            for(int j = 0; j < oldfact.size(); ++j)
            {
                int p = oldfact[j].first;
                to_process[p].push_back(event(i, x, 0));
            }
            cval[x] = y;
            vector <pair<int, int>> pfact = factorise(y);
            for(int j = 0; j < pfact.size(); ++j)
            {
                int p = pfact[j].first, c = pfact[j].second;
                to_process[p].push_back(event(i, x, c));
            }
        }
        else
        {
            int u, v, k;
            cin >> u >> v >> k;
            vector <pair<int, int>> pfact = factorise(k);
            for(int j = 0; j < pfact.size(); ++j)
            {
                int p = pfact[j].first, c = pfact[j].second;
                to_process[p].push_back(event(i, u, v, c));
            }
            queries.push_back(i);
        }
        ans[i] = true;
    }
    dfs(1, 0);
    for(int j = 1; j < 18; ++j)
    {
        for(int i = 1; i <= n; ++i)
            par[i][j] = par[par[i][j - 1]][j - 1];
    }
    memset(cval, 0, sizeof cval);
    for(int p = 2; p < 200005; ++p)
    {
        vector <int> changed;
        for(int i = 0; i < to_process[p].size(); ++i)
        {
            int ty = to_process[p][i].type;
            if(ty == 1)
            {
                int set_to = to_process[p][i].val, node = to_process[p][i].v1;
                int curr_val = cval[node];
                add_val_to_subtree(node, set_to-curr_val);
                cval[node] = set_to;
                changed.push_back(node);
            }
            else
            {
                int u = to_process[p][i].v1, v = to_process[p][i].v2;
                int l = lca(u, v);
                int path_sum = get_path_val(u) + get_path_val(v) - get_path_val(l) - get_path_val(par[l][0]);
                if(path_sum < to_process[p][i].val)
                    ans[to_process[p][i].index] = false;
            }
        }
        sort(changed.begin(), changed.end());
        changed.resize(unique(changed.begin(), changed.end()) - changed.begin());
        for(int i = 0; i < changed.size(); ++i)
        {
            add_val_to_subtree(changed[i], -cval[changed[i]]);
            cval[changed[i]] = 0;
        }
    }
    for(int i = 0; i < queries.size(); ++i)
    {
        if(ans[queries[i]])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
