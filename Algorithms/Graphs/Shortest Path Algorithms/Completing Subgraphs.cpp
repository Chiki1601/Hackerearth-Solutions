#include <bits/stdc++.h>
using namespace std; 
int n, curr, memo[100005], spoilt[1000050], D[1000050], tree[2][400020];
vector<pair<int, int>> v[1000050];
 
int get(int node, int idx)
{
    if(!idx)
        return n + node;
    return 5 * n + node;
}
 
void build_tree(int idx, int node, int l, int r)
{
    if(l == r)
    {
        if(!idx)
            v[l].push_back(pair<int, int>(get(node, idx), 0));
        else
            v[get(node, idx)].push_back(pair<int, int>(l, 0));
        return;
    }
    int m = (l + r) >> 1;
    build_tree(idx, 2 * node, l, m);
    build_tree(idx, 2 * node + 1, m + 1, r);
    if(!idx)
    {
        v[get(2 * node, idx)].push_back(pair<int, int>(get(node, idx), 0));
        v[get(2 * node + 1, idx)].push_back(pair<int, int>(get(node, idx), 0));
    }
    else
    {
        v[get(node, idx)].push_back(pair<int, int>(get(2 * node, idx), 0));
        v[get(node, idx)].push_back(pair<int, int>(get(2 * node + 1, idx), 0));
    }
}
 
void edge_adder(int idx, int node, int l, int r, int a, int b, int vertex)
{
    if(b < l || r < a)
        return;
    if(a <= l && r <= b)
    {
        if(!idx)
            v[get(node, idx)].push_back(pair<int, int>(vertex, 1));
        else
            v[vertex].push_back(pair<int, int>(get(node, idx), 1));
        return;
    }
    int m = (l + r) >> 1;
    edge_adder(idx, 2 * node, l, m, a, b, vertex);
    edge_adder(idx, 2 * node + 1, m + 1, r, a, b, vertex);
}
 
void dijkstra(int s)
{
    for(int i = 0; i < curr; ++i)  
        D[i] = INT_MAX;
    priority_queue <pair<int, int>> pq;
    D[s] = 0;
    pq.push(make_pair(0 , s));
    while(!pq.empty())
    {
        int node = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(D[node] < cost)
            continue;
        for(auto it : v[node])
        {
            int next = it.first;
            long long d = cost + it.second;
            if(spoilt[next])
              continue;
            if(D[next] > d)
            {
                D[next] = d;
                pq.push(make_pair(-d , next));
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, m, a, b, q, t, it;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(pair<int, int>(b, 2));
        v[b].push_back(pair<int, int>(a, 2));
    }
    build_tree(0, 1, 1, n);
    build_tree(1, 1, 1, n);
    curr = 9 * n + 1;
    it = 1;
    cin >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> a >> b;
            edge_adder(0, 1, 1, n, a, b, curr);
            edge_adder(1, 1, 1, n, a, b, curr);
            memo[it++] = curr;
            curr++;
        }
        else if(t == 2)
        {
            cin >> a;
            spoilt[memo[a]] = 1;
        }
        else if(t == 3)
        {
            cin >> a >> b;
            dijkstra(a);
            (D[b] == INT_MAX) ? printf("-1\n") : printf("%d\n", D[b] / 2);
        }
    }
    return 0;
}
