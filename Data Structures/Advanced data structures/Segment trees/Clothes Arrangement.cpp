#include <bits/stdc++.h>
using namespace std;
int nn, roots[100100], c[1001000];
 
struct Node 
{
    int c, l, r;
} nodes[20120100];
 
void inc(int r, int i) 
{
    for(int b = 1 << 19; b > 0; b >>= 1) 
    {
        auto& nd = nodes[r];
        ++nd.c;
        if(b & i) 
        {
            if(nd.r == 0) 
                nd.r = nn++;
            r = nd.r;
        } 
        else 
        {
            if(nd.l == 0) 
                nd.l = nn++;
            r = nd.l;
        }
    }
    ++nodes[r].c;
}
 
void dec(int r, int i) 
{
    for(int b = 1 << 19; b > 0; b >>= 1) 
    {
        auto& nd = nodes[r];
        --nd.c;
        if(b & i) 
            r = nd.r; 
        else 
            r = nd.l;
    }
    --nodes[r].c;
}
 
void dmp(int r, int x, int y) 
{
    const auto& nd = nodes[r];
    if(nd.c < 1) 
        return;
    if(y > 0) 
    {
        if(nd.l > 0) 
            dmp(nd.l, x << 1, y - 1);
        if(nd.r > 0) 
            dmp(nd.r, (x << 1) + 1, y - 1);
    } 
    else 
        cout << x << ": " << nd.c << endl;
}
 
int loc(int r, int y) 
{
    int x = 0;
    for(int b = 1 << 19; b > 0; b >>= 1) 
    {
        auto& nd = nodes[r];
        int dy = nd.r > 0 ? nodes[nd.r].c : 0;
        if(dy >= y) 
        {
            x |= b;
            r = nd.r;
        } 
        else 
        {
            y -= dy;
            r = nd.l;
        }
    }
    return x;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    nn = 1;
    for(int i = 1; i < 100100; ++i) 
        roots[i] = nn++;
    int n, q;
    cin >> n;
    for(int i = 0, x; i < n && cin >> x; ++i) 
        inc(roots[x], i);    
    cin >> q;
    int nq = n + q, rest = n;
    for(int i = 0; i < n; ++i) 
    {
        for(int u = i + 1; u <= nq; u += u & -u) 
            ++c[u];
    }
    for(int i = 0, o, x, y; i < q && cin >> o; ++i) 
    {
        if(1 == o) 
        {
            cin >> x;
            inc(roots[x], n++);
            for(int u = n; u <= nq; u += u & -u) 
                ++c[u];
            ++rest;
        } 
        else 
        {
            cin >> x >> y;
            if(nodes[roots[x]].c >= y) 
            {
                int j = loc(roots[x], y), ans = rest;
                for(int u = j + 1; u > 0; u -= u & -u) 
                    ans -= c[u];
                cout << ans << endl;
                for(int u = j + 1; u <= nq; u += u & -u) 
                    --c[u];
                dec(roots[x], j);
                --rest;
            } 
            else 
                cout << -1 << endl;
        }
    }
    return 0;
}
