#include <bits/stdc++.h>
using namespace std; 
long long n, q, nNode, f[100009], s[100009], e[100009], times, ver[100009], pos[100009], nxt;
vector<pair<int, int>> a[100009];
vector<long long> b;
 
struct node 
{
    long long l, r, val;
};node t[20000180];
 
long long update(long long p, long long old, long long l = 1, long long r = n) 
{
    long long i = ++nNode;
    t[i] = t[old];
    if(l == r) 
    {
        t[i] = {0, 0, t[i].val + 1};
        return i;
    }
    long long m = (l + r) >> 1;
    if(p <= m) 
        t[i].l = update(p, t[old].l, l, m);
    else 
        t[i].r = update(p, t[old].r, m+1, r);
    t[i].val = t[t[i].l].val + t[t[i].r].val;
    return i;
}
 
void dfs(long long u, long long par, long long sum) 
{
    s[u] = ++times, f[u] = sum;
    b.push_back(f[u]);
    for(auto e : a[u]) 
    {
        long long v = e.first, w = e.second;
        if(v != par) 
            dfs(v, u, sum + w);
    }
    e[u] = times;
}
 
long long get(long long u, long long v, long long k, long long l = 1, long long r = n) 
{
    long long val = t[t[v].l].val - t[t[u].l].val;
    if(l == r) 
        return l;
    long long m = (l + r) >> 1;
    if(k <= val) 
        return get(t[u].l, t[v].l, k, l, m);
    else 
        return get(t[u].r, t[v].r, k - val, m + 1, r);
}
 
void go(long long u, long long par) 
{
    ver[s[u]] = update(pos[u], ver[nxt]);
    nxt = s[u];
    for(auto e : a[u]) 
        if(e.first != par) 
            go(e.first, u);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w}), a[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 1; i <= n; i++) 
        pos[i] = lower_bound(b.begin(), b.end(), f[i]) - b.begin() + 1;
    go(1,0);
    cin >> q;
    for(int i = 1; i <= q; i++) 
    {
        long long v, k;
        cin >> v >> k;
        if(e[v] - s[v] < k) 
            cout << "-1" << endl;
        else 
        {
            long long j = get(ver[s[v]], ver[e[v]], k);
            cout << b[j - 1] - f[v] << endl;
        }
    }
    return 0;
}
