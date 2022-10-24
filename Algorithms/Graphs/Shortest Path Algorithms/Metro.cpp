#include <bits/stdc++.h>
using namespace std;
 
struct Edge
{
    int u, w;
    long long t;
};vector<Edge> g[100014];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, st, t, ver[100014];
    long long d[100014];
    cin >> n >> m;
    while(m--)
    {
        int sz;
        long long t;
        cin >> sz >> t;
        for(int i = 0; i < sz; i++)
        {    
            cin >> ver[i]; 
            ver[i]--;
        }
        for(int i = 0; i < sz - 1; i++)
        {
            int w;
            cin >> w;
            g[ver[i]].push_back({ver[i + 1], w, t});
            t += w;
        }
    }
    cin >> st >> t;
    st--, t--;
    memset(d, 63, sizeof d);
    d[st] = 0;
    set<pair<long long, int> > s({{d[st], st}});
    while(s.size())
    {
        int v = s.begin() -> second;
        if(v == t)
            return cout << d[v] << '\n', 0;
        s.erase(s.begin());
        for(auto edge : g[v])
            if(d[v] <= edge.t && d[edge.u] > d[v] + edge.w)
            {
                s.erase({d[edge.u], edge.u});
                d[edge.u] = d[v] + edge.w;
                s.insert({d[edge.u], edge.u});
            }
    }
    cout << "-1" << endl;
}
