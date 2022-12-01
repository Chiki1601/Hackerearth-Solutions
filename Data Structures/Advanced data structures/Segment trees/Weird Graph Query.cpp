#include <bits/stdc++.h>
using namespace std;
vector <int> que[1010], t[1010 << 2];
pair <int, int> a[1010];
int n, m, q, ans[200010], ql[200010], qr[200010], qk[200010], d[1010];
 
void init(int u = 1, int b = 1, int e = n) 
{
    t[u].clear();
    if(b == e) 
        return void(t[u] = {a[b].second});
    int mid = b + e >> 1;
    init(u << 1, b, mid), init(u << 1 | 1, mid + 1, e);
    merge(t[u << 1].begin(), t[u << 1].end(), t[u << 1 | 1].begin(), t[u << 1 | 1].end(), back_inserter(t[u]));
}
 
int query(int l, int r, int k, int u = 1, int b = 1, int e = n) 
{
    if(b == e) 
        return t[u][0];
    int mid = b + e >> 1, tot = upper_bound(t[u << 1].begin(), t[u << 1].end(), r) - lower_bound(t[u << 1].begin(), t[u << 1].end(), l);
    if(tot >= k) 
        return query(l, r, k, u << 1, b, mid);
    return query(l, r, k - tot, u << 1 | 1, mid + 1, e);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector <pair <int, int>> g[1010];
    while(m--) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    cin >> q;
    for(int i = 1, u; i <= q; ++i) 
    {
        cin >> u >> ql[i] >> qr[i] >> qk[i];
        que[u].emplace_back(i);
    }
    for(int src = 1; src <= n; ++src) 
    {
        if(que[src].empty()) 
            continue;
        priority_queue <pair <int, int>> pq;
        for(int i = 1; i <= n; ++i) 
            d[i] = 1000000005;
        d[src] = 0, pq.emplace(0, src);
        while(!pq.empty()) 
        {
            auto it = pq.top(); 
            pq.pop();
            if(-it.first > d[it.second]) 
                continue;
            int u = it.second;
            for(auto e : g[u]) 
            {
                int v = e.first, w = e.second;
                if(d[u] + w < d[v]) 
                {
                    d[v] = d[u] + w; 
                    pq.emplace(-d[v], v);
                }
            }
        }
        for(int i = 1; i <= n; ++i) 
            a[i] = make_pair(d[i], i);
        sort(a + 1, a + n + 1); 
        init();
        for(auto it : que[src]) 
        {
            auto [l, r, k] = make_tuple(ql[it], qr[it], qk[it]);
            ans[it] = d[query(l, r, k)];
        }
    }
    for(int i = 1; i <= q; ++i) 
        cout << ans[i] << endl;
  return 0;
}
