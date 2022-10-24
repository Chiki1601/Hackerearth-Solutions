#include <bits/stdc++.h>
using namespace std; 
vector<pair<int, int>> g[1024], rg[1024];
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long dist[1024];
    int n, m, q, o[1024], throttle[1024];
    unordered_map<int, long long> t[1024];
    cin >> n >> m >> q;
    for(int i = 0; i < n; ++i) 
        cin >> o[i];
    for(int i = 0, x, y, z; i < m && cin >> x >> y >> z; ++i) 
    {
        g[x].push_back(make_pair(y, z));
        rg[y].push_back(make_pair(x, z));
    }
    {
        priority_queue<tuple<long long, int>> que;
        memset(dist, 0x3f, sizeof(dist));
        que.emplace(0, n - 1);
        while(!que.empty()) 
        {
            long long d;
            int a;
            tie(d, a) = que.top();
            que.pop();
            d = -d;
            if(d > dist[a]) 
                continue;
            dist[a] = d;
            for(const auto p : rg[a]) 
            {
                long long d1 = d + p.second;
                int a1 = p.first;
                if(d1 < dist[a1]) 
                {
                    dist[a1] = d1;
                    throttle[a1] = throttle[a] + 1;
                    que.emplace(-d1, a1);
                }
            }
        }
    }
    {
        priority_queue<tuple<long long, long long, int>> que;
        if(o[0] != 0)
            que.emplace(-dist[0], 0, 0);
        while(!que.empty()) 
        {
            long long d0, d;
            int a;
            tie(d0, d, a) = que.top();
            que.pop();
            d = -d;
            int r = d % q;
            if(t[a].find(r) != t[a].end()) 
                continue;
            t[a][r] = d;
            if(a == n - 1) 
                break;
            for(const auto p : g[a]) 
            {
                long long d1 = d + p.second;
                int r1 = d1 % q, a1 = p.first;
                if(r1 == o[a1]) 
                    continue;
                if(t[a1].size() > throttle[a1]) 
                    continue;
                que.emplace(-(d1 + dist[a1]), -d1, a1);
            }
        }
        cout << (t[n - 1].empty() ? -1LL : t[n - 1].begin()->second) << '\n';
    }
    return 0;
}
