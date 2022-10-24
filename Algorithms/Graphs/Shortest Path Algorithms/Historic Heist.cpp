#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    long long t = 1;
    cin >> t;
    while(t--)
    {
        long long n, start, dest, m, three;
        cin >> n;
        vector<long long> ifpol(n);
        for(long long i = 0; i < n; i++)
            cin >> ifpol[i];
        cin >> start >> dest;
        start--, dest--;
        cin >> m >> three;
        vector<vector<pair<long long, long long>>> adj(n);
        for(long long i = 0; i < m; i++)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        vector<long long> dist(n, INT_MAX), pdist(n, INT_MAX);
        set<pair<long long, long long>> s;
        dist[start] = 0;
        for(long long i = 0; i < n; i++)
        {
            if(ifpol[i])
            {
                pdist[i] = 0;
                s.insert({pdist[i], i});
            }
        }
        while(!s.empty())
        {
            auto x = *s.begin();
            s.erase(s.begin());
            for(auto it : adj[x.second])
            {
                if(pdist[it.first] > pdist[x.second] + it.second)
                {
                    s.erase({pdist[it.first], it.first});
                    pdist[it.first] = pdist[x.second] + it.second;
                    s.insert({pdist[it.first], it.first});
                }
            }
        }
        s.clear();
        s.insert({dist[start], start});
        while(!s.empty())
        {
            auto x = *s.begin();
            s.erase(s.begin());
            for(auto it : adj[x.second])
            {
                if(pdist[it.first] > dist[x.second] + it.second and dist[it.first] > dist[x.second] + it.second)
                {
                    s.erase({dist[it.first], it.first});
                    dist[it.first] = dist[x.second] + it.second;
                    s.insert({dist[it.first], it.first});
                }
            }
        }
        if(dist[dest] == INT_MAX)
            cout << "-1";
        else 
            cout << dist[dest];  
        cout << endl;
    }
}
