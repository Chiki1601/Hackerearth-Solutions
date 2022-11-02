#include<bits/stdc++.h>
using namespace std;
int sz = 0, eg = 0, deg[200001];
vector<int> graph[200001];
bool visit[200001];
 
void dfs(int node)
{
    sz++;
    visit[node] = 1;
    eg += deg[node];
    for(int i: graph[node])
    {
        if(visit[i] == 0)
        {
            visit[i] = 1;
            dfs(i);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , k, u[200001], v[200001], w[200001];
    cin >> n >> m >> k;
    vector<pair<int, int>> watered, dry;
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        graph[u[i]].push_back(v[i]);
        graph[v[i]].push_back(u[i]);
        ++deg[u[i]];
        ++deg[v[i]];
    }
    for(int i = 0; i < k; i++)
        cin >> w[i];
    long long int ans1 = 0 , ans2 = 0, maxsz = 0, pre = 0 , cur = 0;
    for(int i = 0; i < k; i++)
    {
        sz = 0;
        eg = 0;
        if(visit[w[i]] == 1)
            continue;
        dfs(w[i]);
        maxsz = max(maxsz , (long long int)sz);
        eg /= 2;
        watered.push_back(make_pair(sz , eg));
        ans1 += (sz * (sz - 1)) / 2 - eg;
    }
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 0)
        {
            sz = 0;
            eg = 0;
            dfs(i);
            eg /= 2;
            dry.push_back(make_pair(sz , eg));
            ans1 += (sz * (sz - 1)) / 2 - eg;
        }
    }
    sort(watered.begin() , watered.end());
    for(int i = 0; i < dry.size(); i++)
    {
        ans2 = ans2 + pre * dry[i].first;
        ans1 += pre * dry[i].first;
        pre += dry[i].first;
    }
    ans2 += pre * maxsz;
    ans1 += pre * maxsz;
    cout << ans1 << " " << ans2;
}
