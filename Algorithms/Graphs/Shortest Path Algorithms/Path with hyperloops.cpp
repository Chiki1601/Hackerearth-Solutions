#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, m, k, st, en; 
    cin >> n >> m >> k >> st >> en;
    vector<set<pair<long long int, long long int>>> graph;
    graph.resize(n + 2);
    for(long long int i = 0; i < m; i++)
    {
        long long int x, y; 
        cin >> x >> y;
        graph[x].insert({y, 1});
        graph[y].insert({x, 1});
    }
    for(long long int i = 0; i < k; i++)
    {
        long long int x, y; 
        cin >> x >> y;
        graph[x].insert({y, 2});
        graph[y].insert({x, 2});
    }
    vector<long long int>dist(n + 2, 10000000000000000);
    dist[st] = 0;
    set<pair<long long int, long long int>> ok;
    ok.insert({dist[st], st});
    while(!ok.empty())
    {
        auto fr = *ok.begin();
        ok.erase(ok.find(fr));
        for(auto &edge : graph[fr.second])
        {
            if((fr.first + edge.second) < dist[edge.first])
            {
                pair<long long int, long long int> lr = {dist[edge.first], edge.first};
                if(ok.find(lr) != ok.end())
                    ok.erase(ok.find(lr));
                dist[edge.first] = fr.first + edge.second;
                lr = {dist[edge.first], edge.first};
                ok.insert(lr);
            }
        }
    }
    if(dist[en] >= 1000000000000000)
        dist[en] = -1;
    cout << dist[en] << endl;
    return 0;
}
