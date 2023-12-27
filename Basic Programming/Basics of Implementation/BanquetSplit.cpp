#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000000];
int n, H[1000000], up[1000000][21], tin[1000000], tout[1000000], timer, l;

void dfs(int node, int p = 0, int h = 0) 
{
    tin[node] = ++timer;
    up[node][0] = p;
    H[node] = h++;
    for(int i = 1; i <= l; ++i)
        up[node][i] = up[up[node][i - 1]][i - 1];
    for(auto c : g[node])
        if(c != p) 
            dfs(c, node, h);
    tout[node] = ++timer;
}

inline bool upper(int a, int b) 
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) 
{
    for(int i = l; i >= 0; --i)
        if(!upper(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i)
            g[i].clear();
        for(int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u; 
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        timer = 0;
        l = 1;
        while((1 << l) <= n)  
            ++l;
        dfs(0);
        int q;
        cin >> q;
        while(q--) 
        {
            int u, v;
            cin >> u >> v;
            --u; 
            --v;
            if((H[u] & 1) != (H[v] & 1)) 
                cout << "Yes\n";
            else 
            {
                cout << "No\n";
                cout << "1 ";
                if(H[u] > H[v]) 
                    swap(u, v);
                if(upper(u, v))
                    cout << H[v] - H[u] + 1 << "\n";
                else 
                {
                    int h = H[lca(u, v)] * 2 ;
                    cout << H[u] + H[v] - h + 1 << "\n";
                }
            }
        }
    }
    return 0;
}
