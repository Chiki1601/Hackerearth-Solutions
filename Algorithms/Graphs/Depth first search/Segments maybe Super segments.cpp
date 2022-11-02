#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, dsu[200007];
long long p[200007];
 
int root(int u) 
{
    int k = dsu[u];
    if(k < 0) 
        return u;
    dsu[u] = root(k);
    p[u] += p[k];
    return dsu[u];
}
 
bool join(int u, int v, int cost) 
{
    int x = root(u), y = root(v); 
    if(x == y) 
        return 0;
    if(dsu[x] > dsu[y]) 
    {
        swap(x, y); 
        swap(u, v); 
        cost *= -1;
    } 
    p[y] = p[u] + cost - p[v]; 
    dsu[x] += dsu[y]; 
    dsu[y] = x;
    return 1;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) 
    {
        cin >> n >> m >> k;
        memset(dsu, -1, sizeof(int) * (n + 7));
        memset(p, 0, sizeof(long long) * (n + 7));
        int l, r, v;
        for(int i = 1; i <= m; i++) 
        {
            cin >> l >> r >> v;
            join(l, r + 1, v);
        }
        for(int i = 1; i <= k; i++) 
        {
            cin >> l >> r;
            if(root(l) != root(r + 1)) 
                cout << "-1";
            else 
                cout << p[r + 1] - p[l];
            cout << endl;
        }
    }
    return 0;
}
