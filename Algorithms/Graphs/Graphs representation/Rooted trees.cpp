#include <bits/stdc++.h>
using namespace std;
int st[100014], en[100014], ver[100014];
vector<int> g[100014];
 
void dfs(int v = 0, int p = -1) 
{
    static int time;
    if(p == -1)
        time = 0;
    ver[time] = v;
    st[v] = time++;
    for(auto u : g[v])
        if(u != p)
            dfs(u, v);
    en[v] = time;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, y, q, a[100014];
    set<int> ley;
    cin >> t;
    while(t--) 
    {
        cin >> n >> q >> y;
        fill(g, g + n, vector<int>());
        fill(a, a + n, 0);
        for(int i = 0; i < n - 1; ++i) 
        {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        ley.clear();
        for(int i = 0; i < n; ++i)
            ley.insert(ley.begin(), i);
        dfs();
        while(q--) 
        {
            int t, v;
            cin >> t >> v;
            --v;
            if(t == 0) 
            {
                int x;
                cin >> x;
                auto it = ley.lower_bound(st[v]);
                while (it != ley.end() && *it < en[v]) 
                {
                    int u = ver[*it];
                    a[u] += x;
                    if (a[u] >= y)
                        it = ley.erase(it);
                    else
                        ++it;
                }
            }
            else
                cout << a[v] << endl;
        }
    }
}
