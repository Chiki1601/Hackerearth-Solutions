#include <bits/stdc++.h>
using namespace std;
int n , m, p[100005], d[100005]; 
vector<int> b[100005];
 
void add(int x , vector<int> &b) 
{
    for(int i = 0; i < b.size(); i++) 
    {
        int t = b[i]; 
        if((x ^ t) < x) 
            x ^= t;
    }
    if(x == 0)
        return;
    for(int i = 0; i < b.size(); i++)
    {
        if((x ^ b[i]) < b[i])
            b[i] ^= x;
    }
    b.push_back(x); 
    sort(b.begin(), b.end(), greater<int>());
}
 
int mx(int x , vector<int> &b)
{
    for(int i = 0; i < b.size(); i++)
    {
        int t = b[i];
        if((x ^ t) > x)
            x ^= t;
    }
    return x;
}
 
int find(int u)
{
    if(u == p[u])
        return u;
    int P = p[u]; 
    int root = find(P); 
    d[u] ^= d[P]; 
    p[u] = root; 
    return root; 
}
 
void init(int n) 
{
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        b[i].clear();
        d[i] = 0;
    }
}
 
void merge(int u , int v , int w) 
{
    int pu = find(u) , pv = find(v);
    if(pu == pv) 
    {
        add(w ^ d[u] ^ d[v] , b[pu]); 
        return;
    }
    p[pv] = pu; 
    d[pv] = d[v] ^ d[u] ^ w;
    for(auto x : b[pv])
        add(x , b[pu]); 
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    assert(cin >> n);
    assert(1 <= n && n <= 100000);
    init(n);
    cin >> q;
    assert(1 <= q && q <= 100000);
    while(q--)
    {
        int type;
        assert(cin >> type);
        assert(1 <= type && type <= 2);
        if(type == 1)
        {
            int u , v , w;
            assert(cin >> u >> v >> w);
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= n);
            assert(1 <= w && w <= 1e9);
            u--;v--;
            merge(u , v , w);
        }
        else
        {
            int u , v;
            assert(cin >> u >> v);
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= n);
            u--;v--;
            if(find(u) != find(v))
            {
                cout << -1 << endl;
                continue;
            }            
            cout << mx(d[u] ^ d[v] , b[find(u)]) << endl;
        }
    }
}
