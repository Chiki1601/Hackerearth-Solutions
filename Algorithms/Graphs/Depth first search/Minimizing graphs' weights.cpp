#include "bits/stdc++.h"
using namespace std;
vector<int> dsu, mi;
 
int find(int u) 
{
    if(u == dsu[u]) 
        return u;
    return dsu[u] = find(dsu[u]);
}
 
bool uni(int u, int v) 
{
    u = find(u); 
    v = find(v);
    if(u == v) 
        return 0;
    dsu[u] = v;
    mi[v] = min(mi[v], mi[u]);
    return 1;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    { 
        int n, m;
        cin >> n >> m;
        dsu.assign(n, 0);
        iota(dsu.begin(), dsu.end(), 0);
        mi.clear();
        vector<int> a(n);
        for(auto &it: a) 
        {
            cin >> it;
            mi.emplace_back(it);
        }
        vector<tuple<int, int, int>> v;
        for(int i = 0, x, y, w; i < m; i++) 
        {
            cin >> x >> y >> w; 
            x--; 
            y--;
            v.emplace_back(w, x, y);
        }
        sort((v).begin(), (v).end());
        long long sum = 0;
        for(auto &[w, x, y]: v) 
        {
            if(uni(x, y)) 
                sum += w;
        }
        int mit = INT_MAX;
        for(int i = 0; i < n; i++) 
            if(dsu[i] == i) 
            {
                mit = min(mit, mi[i]);
                sum += mi[i];
            }
            sum -= mit;
            cout << sum << endl;
    }
    return 0;
}
