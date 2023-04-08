#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, max(u, v)});
        adj[v].push_back({u, max(u, v)});
    }
    vector<int> prime(n + 1, 0), dis(n + 1, 10000000);
    for(int i = 2; i * i <= n; i++)
    {
        if(prime[i] == 0)
        {
            for(int j = i * i; j <= n; j += i)
                prime[j] = 1;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 2; i <= n; i++)
    {
        if(prime[i] == 0)
        {
            pq.push({0, i});
            dis[i] = 0;
        }
    }
    while(!pq.empty())
    {
        pair<int, int> pa = pq.top();
        int cost = pa.first, p = pa.second;
        pq.pop();
        for(int i = 0; i < adj[p].size(); i++)
        {
            if(cost + adj[p][i].second < dis[adj[p][i].first])
            {
                dis[adj[p][i].first] = cost + adj[p][i].second;
                pq.push({dis[adj[p][i].first], adj[p][i].first});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(dis[i] == 10000000)
            cout << "-1 ";
        else
            cout << dis[i] << " ";
    }
    cout << endl;
}
