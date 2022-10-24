#include <bits/stdc++.h>
using namespace std;
bool a[100005];
int f[100005], id[100005];
 
struct edge 
{
    int x, y, w;
};edge e[100005], q[100005];
 
bool cmp1(const edge &a, const edge &b) 
{
    return a.w < b.w;
}
 
bool cmp2(const int &a, const int &b) 
{
    return cmp1(q[a], q[b]);
}
 
int getf(int x) 
{
    return (f[x] == x) ? x : (f[x] = getf(f[x]));
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; ++i) 
        f[i] = i;
    --n;
    for(int i = 0; i < n; ++i) 
    {
        cin >> e[i].x >> e[i].y >> e[i].w;
        --e[i].x;
        --e[i].y;
    }
    sort(e, e + n, cmp1);
    cin >> m;
    for(int i = 0; i < m; ++i) 
    {
        id[i] = i;
        cin >> q[i].x >> q[i].y >> q[i].w;
        --q[i].x;
        --q[i].y;
    }
    sort(id, id + m, cmp2);
    for (int i = 0, j = 0; i < m; ++i) 
    {
        for (; j < n && e[j].w <= q[id[i]].w; ++j) 
        {
            int x = getf(e[j].x), y = getf(e[j].y);
            f[x] = y;
        }
        a[id[i]] = getf(q[id[i]].x) != getf(q[id[i]].y);
    }
    for(int i = 0; i < m; ++i) 
        puts(a[i] ? "YES" : "NO");
    return 0;
}
