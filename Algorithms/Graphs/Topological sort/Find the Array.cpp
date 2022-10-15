#include <bits/stdc++.h>
using namespace std;
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
int n, a[100005], b[100005], vis[100005], f[100005];
vector<int> adj[100005], radj[100005], ver;
 
void dfs(int u) 
{
    vis[u] = 1;
    for(int v : adj[u]) 
    {
        if(!vis[v]) 
            dfs(v);
    }
    f[u] = int((ver).size());
    ver.push_back(u);
}
 
int check(int mi) 
{
    reverse((ver).begin(), (ver).end());
    for(int u : ver) 
    {
        int mx = 2046223984;
        for(int v : radj[u]) 
            chkmin(mx, a[v] - 1);
        if(u < mi) 
        {
            if(b[u] > mx) 
            {
                reverse((ver).begin(), (ver).end());
                return 0;
            }
            a[u] = b[u];
        }
        else 
            a[u] = mx;
        if(a[u] <= 0) 
        {
            reverse((ver).begin(), (ver).end());
            return 0;
        }
    }
    reverse((ver).begin(), (ver).end());
    for(int u = 0; u < n; ++u)
    {
        if(a[u] > b[u]) 
            return 1;
        if(a[u] < b[u]) 
            return 0;
    }
    return 0;
}
 
int finish(int mi) 
{
    for(int u : ver) 
    {
        int mx = 1;
        for(int v : adj[u]) 
            chkmax(mx, a[v] + 1);
        if(u < mi) 
        {
            if(b[u] < mx) 
                return 0;
            a[u] = b[u];
        }
        else if(u == mi) 
            a[u] = max(b[u] + 1, mx);
        else 
            a[u] = mx;
    }
    return 1;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int test, m; 
    assert(cin >> test);
    assert(1 <= test && test <= 5);
    while(test--) 
    {
        assert(cin >> n >> m);
        assert(1 <= n && n <= 100000);
        assert(0 <= m && m <= 100000);
        for(int i = 0; i < n; ++i)
        {
            adj[i].clear(); 
            radj[i].clear(); 
            vis[i] = 0;
        }
        for(int i = 0; i < n; ++i)
        {
            assert(cin >> b[i]);
            assert(1 <= b[i] && b[i] <= 1000000000);
        }
        for(int i = 0; i < m; ++i)
        {
            int u, v; 
            string sign; 
            assert(cin >> u >> sign >> v); 
            u--, v--;
            assert(0 <= u && u < n);
            assert(0 <= v && v < n);
            assert(sign == "<" || sign == ">");
            if(sign == "<") 
                swap(u, v);
            adj[u].push_back(v); 
            radj[v].push_back(u);
        }
        ver.clear();
        for(int u = 0; u < n; ++u)
            if(!vis[u]) 
                dfs(u);
        int found = 0;
        for(int u = 0; u < n; ++u)
        {
            for(int v : adj[u]) 
            {
                if(f[u] < f[v]) 
                    found = 1;
            }
        }
        if(found) 
        {
            cout << "NO" << endl;
            continue;
        }
        int lo = 0, hi = n - 1;
        while(lo < hi) 
        {
            int mi = lo + hi + 1 >> 1;
            if(check(mi)) 
                lo = mi;
            else 
                hi = mi - 1;
        }
        assert(check(lo + hi >> 1));
        assert(finish(lo + hi >> 1));
        cout << "YES" << endl;
        for(int i = 0; i < n; ++i) 
            cout << a[i] << " \n"[i == n - 1];
    }
    string s; 
    assert(!(cin >> s));
    return 0;
}
