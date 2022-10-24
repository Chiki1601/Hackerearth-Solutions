#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    for(int n, m; T-- > 0 && cin >> n >> m; ) 
    {
        vector<vector<int>> g(n + 1);
        for(int i = 1, x, y; i < n && cin >> x >> y; ++i) 
        {
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> d(n + 1, -1);
        auto bfs = [&](int z) 
        {
            deque<int> q;
            q.push_back(z);
            d[z] = 0;
            while(!q.empty()) 
            {
                int x = q.front();
                q.pop_front();
                for(int y : g[x]) 
                    if (d[y] < 0) 
                    {
                        d[y] = d[x] + 1;
                        q.push_back(y);
                    }
            }
        };
        vector<int> a(m);
        for(int i = 0; i < m; ++i) 
            cin >> a[i];
        bfs(a[0]);
        bool ok = true;
        for(int x : a) 
            if (d[x] % 2 != d[a[0]] % 2) 
            {
                ok = false;
                break;
            }
            if(ok)
            {
                int u = 0, v = -1;
                for (int x : a) 
                    if (d[x] > v) 
                        u = x, v = d[x];
                fill(d.begin(), d.end(), -1);
                bfs(u);
                v = -1;
                for (int x : a) 
                    v = max(v, d[x]);
                cout << (v / 2) << endl;
            } 
            else 
                cout << -1 << endl;
    }
    return 0;
}
