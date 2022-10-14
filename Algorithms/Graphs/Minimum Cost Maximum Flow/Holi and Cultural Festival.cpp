#include<bits/stdc++.h>
using namespace std;
long long int n, prog[3010], webd[3010], dist[3010], curflow[3010], fans, cans, w, p, m, market[3010];
pair<long long int, long long int>par[3010];
 
struct edge
{
    long long int to, rev, cost, fl, cap;
};vector<edge>v[3010];
 
void add_edge(long long int fr, long long int to, long long int cap, long long int cost)
{
    v[fr].push_back({to,(int)v[to].size(),cost,0,cap});
    v[to].push_back({fr,(int)v[fr].size()-1,-cost,0,0});
}
 
long long int spfa(long long int src, long long int dest)
{
    long long int i, j, k;
    queue<long long int>q;
    bool mark[3010];
    for(i = 1; i <= 3007; i++)
    {
        mark[i] = curflow[i] = 0;
        dist[i] = 10000000000;
    }
    curflow[src] = 10000000000;
    dist[src] = 0;
    mark[src] = 1;
    q.push(src);
    while(!q.empty())
    {
        j = q.front();
        q.pop();
        mark[j] = 0;
        for(i = 0; i < v[j].size(); i++)
        {
            long long int to = v[j][i].to, idx = v[j][i].rev, cst = v[j][i].cost, cap = v[j][i].cap;
            if(cap <= 0 || dist[to] <= cst + dist[j])
                continue;
            curflow[to] = min(curflow[j], cap);
            dist[to] = cst + dist[j];
            par[to] = {j, i};
            if(!mark[to])
            {
                q.push(to);
                mark[to] = 1;
            }
        }
    }
    return curflow[dest];
}
 
long long int augment(long long int src, long long int dest, long long int flow)
{
    for(long long int i = dest; i != src; i = par[i].first)
    {
        edge &temp = v[par[i].first][par[i].second];
        edge &rev = v[i][temp.rev];
        temp.cap -= flow;
        temp.fl += flow;
        rev.cap += flow;
        rev.fl -= flow;
    }
    return 1LL * dist[dest] * flow;
}
 
void min_cost_max_flow(long long int src, long long int dest)
{
    long long int temp;
    while(temp = spfa(src, dest))
    {
        cans += augment(src, dest, temp);
        fans += temp;
    }
}
 
int main()
{
    long long int i, j, k, src, sink, wb, pg, mr;
    cin >> n >> w >> p >> m;
    src = n + 1;
    sink = n + 2;
    wb = n + 3;
    pg = n + 4;
    mr = n + 5;
    for(i = 1; i <= n; i++)
    {
        cin >> webd[i];
        add_edge(i, wb, 1, -webd[i]);
    }
    for(i = 1; i <= n; i++)
    {
        cin >> prog[i];
        add_edge(i, pg, 1, -prog[i]);
    }
    for(i = 1; i <= n; i++)
    {
        cin >> market[i];
        add_edge(i, mr, 1, -market[i]);
    }
    for(i = 1; i <= n; i++)
        add_edge(src, i, 1, 0);
    add_edge(wb, sink, w, 0);
    add_edge(pg, sink, p, 0);
    add_edge(mr, sink, m, 0);
    min_cost_max_flow(src, sink);
    cout << abs(cans) << endl;
    return 0;
}
