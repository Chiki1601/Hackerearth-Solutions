#include <bits/stdc++.h>
using namespace std;
vector<int>g[500014];
int st[500014], en[500014], Time, lazy[500014 << 2], n, q;
bool state[500014];
 
struct node
{
    int m, n;
}  s[500014 << 2], emp = {1717171717, 0};
 
node operator &(const node &a, const node &b)
{
    if(a.m < b.m)
        return a;
    if(b.m < a.m)
        return b;
    return {a.m, a.n + b.n};
}
 
void shift(int id)
{
    if(!lazy[id])
        return;
    lazy[id<<1] += lazy[id], lazy[id<<1|1] += lazy[id];
    s[id<<1].m += lazy[id];
    s[id<<1|1].m += lazy[id];  
    lazy[id] = 0;
}
 
node get(int st, int en, int l = 0, int r = n, int id = 1)
{
    if(en <= l || r <= st)
        return emp;
    if(st <= l && r <= en)
        return s[id];
    shift(id);
    int mid = (l + r) >> 1;
    return get(st, en, l, mid, id << 1) & get(st, en, mid, r, id << 1 | 1);
}
 
void add(int st, int en, int v = 1, int l = 0, int r = n, int id = 1)
{
    if(en <= l || r <= st)
        return;
    if(st <= l && r <= en)
    {
        s[id].m += v;
        lazy[id] += v;
        return;
    }
    shift(id);
    int mid = (l + r) >> 1;
    add(st, en, v, l, mid, id << 1);
    add(st, en, v, mid, r, id << 1 | 1);
    s[id] = s[id << 1] & s[id << 1 | 1];
}
 
void build(int l = 0, int r = n, int id = 1)
{
    s[id].n = r - l;
    int mid = (l + r) >> 1;
    if(r - l > 1)
        build(l, mid, id << 1), build(mid, r, id << 1 | 1);
}
 
void sten(int v = 0, int p = -1)
{
    st[v] = Time++;
    for(auto &u : g[v])
        if(u != p)
            sten(u, v);
    en[v] = Time;
}
 
void addVer(int v, int x)
{
    add(st[v], en[v], x);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    sten();
    build();
    while(q--)
    {
        int t, v;
        cin >> t >> v;
        v--;
        if(t == 1)
            addVer(v, (state[v] ^= 1) ? +1 : -1);
        else
            cout << !state[v] * get(st[v], en[v]).n << endl;
    }
}
