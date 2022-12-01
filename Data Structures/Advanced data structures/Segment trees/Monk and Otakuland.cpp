#include <bits/stdc++.h>
using namespace std; 
int n, m, seg[800008], lazy[800008];
string s;
 
void build(int id, int l, int r, int i) 
{
    if(i < l || r < i) 
        return;
    if(l == r) 
    {
        seg[id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid, i);
    build(id * 2 + 1, mid + 1, r, i);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
 
void down(int id, int l, int r) 
{
    int gt = lazy[id], mid = (l + r) >> 1; 
    lazy[id] = 0;
    if(gt % 2 == 0) 
        return;
    seg[id * 2] = mid - l + 1 - seg[id * 2];
    lazy[id * 2] += gt;
    seg[id * 2 + 1] = r - mid - seg[id * 2 + 1];
    lazy[id * 2 + 1] += gt;
}
 
void update(int id, int l, int r, int u, int v) 
{
    if(v < l || r < u) 
        return;
    if(u <= l && r <= v) 
    {
        seg[id] = r - l + 1 - seg[id];
        ++lazy[id]; 
        return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
 
int gett(int id, int l, int r, int u, int v) 
{
    if(v < l || r < u) 
        return 0;
    if(u <= l && r <= v) 
        return seg[id];
    down(id, l, r);
    int mid = (l + r) >> 1;
    return (gett(id * 2, l, mid, u, v) + gett(id * 2 + 1, mid + 1, r, u, v));
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '>')
            build(1, 1, n - 1, i + 1);
    while(m--) 
    {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) 
        {
            update(1, 1, n - 1, l, r - 1);
            continue;
        }
        int u = min(l, r), v = max(l, r);
        int g = gett(1, 1, n - 1, u, v - 1);
        if(l < r)
            cout << r - l - g << endl;
        else
            cout << g << endl;
    }
    return 0;
}
