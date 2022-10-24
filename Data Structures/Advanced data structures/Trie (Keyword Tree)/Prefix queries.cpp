#include <bits/stdc++.h>
using namespace std;
int n, q, t[10000000][2], sz = 1, cnt[10000000], a[100014], ans[100014];
vector<int> g[100014];
vector<pair<int, int>> query[100014];
 
void upd(long long x, int v) 
{
    int p = 0;
    for(int i = 61; i >= 0; i--) 
    {
        bool b = x >> i & 1;
        if(!t[p][b])
            t[p][b] = sz++;
        p = t[p][b];
        cnt[p] += v;
    }
}
 
int get(long long x) 
{
    int p = 0, ans = 0;
    for(int i = 61; i >= 0; i--) 
    {
        bool b = x >> i & 1;
        if(t[p][b] && cnt[t[p][b]])
            p = t[p][b];
        else
            break;
        ++ans;
    }
    return ans;
}
 
void dfs(int v = 0, int p = -1) 
{
    upd(a[v], 1);
    for(auto[u, i] : query[v])
        ans[i] = get(u);
    for(auto u : g[v])
        if(u != p)
            dfs(u, v);
    upd(a[v], -1);
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
    {
        cin >> n;
        fill(cnt, cnt + sz, 0);
        fill(*::t, *::t + 2 * sz, 0);
        sz = 1;
        fill(g, g + n, vector<int>());
        fill(query, query + n, vector<pair<int, int>>());
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n - 1; ++i) 
        {
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        cin >> q;
        for(int i = 0; i < q; ++i) 
        {
            int v, x;
            cin >> v >> x;
            --x;
            query[x].emplace_back(v, i);
        }
        dfs();
        for(int i = 0; i < q; ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }
}
