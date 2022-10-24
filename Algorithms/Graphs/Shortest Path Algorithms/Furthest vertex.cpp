#include <bits/stdc++.h>
using namespace std;
bool vis[100002];
pair<int, int> diam[100002];
vector<vector<int>> g(100002);
int n, q, parent[100002], diamL[100002], T[100002], P[100002][18], L[100002];
 
struct query 
{
    int t, a, b;
} Q[300006];
 
void dfs(int x, int level)
{
    vis[x] = true;
    for(int i = 0; i <= (int)(g[x]).size() - 1; ++i)
    {
        int child = g[x][i];
        if(!vis[child])
        {
            T[child] = x;
            L[child] = level + 1;
            dfs(child, level + 1);
        }
    }
}
 
void chRoot(int root)
{
    T[root] = root;
    L[root] = 1;
    dfs(root, 1);
}
 
int query(int p, int q)
{
    if(L[p] < L[q]) 
        swap(p, q);
    int log;
    for(log = 1; (1ll<<log) <= L[p]; log++);
        log--;
    for(int i = log; i >= 0; --i)
        if(L[p] - (1ll << i) >= L[q])
            p = P[p][i];
    if(p == q) 
        return p;
    for(int i = log; i >= 0; i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
        {    
            p = P[p][i]; 
            q = P[q][i];
        }
    return T[p];
}
 
int find(int a)
{
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}
 
pair<int, int> furthest(int x)
{
    int a = diam[find(x)].first, b = diam[find(x)].second;
    int l1 = query(x, a), l2 = query(x, b);
    return max(pair<int, int>(L[x] + L[a] - 2 * L[l1], a), pair<int, int>(L[x] + L[b] - 2 * L[l2], b));
}
 
void merge(int a, int b)
{
    int x = find(a), y = find(b);
    int newDiamL = max(diamL[x], diamL[y]);
    pair<int, int> newDiam = diamL[x] > diamL[y] ? diam[x] : diam[y];
    int curr = 1 + furthest(a).first + furthest(b).first;
    if(curr > newDiamL) 
    {  
        newDiamL = curr; 
        newDiam = pair<int, int>(furthest(a).second, furthest(b).second);
    }
    parent[x] = y;
    diamL[y] = newDiamL;
    diam[y] = newDiam;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> Q[i].t >> Q[i].a;
        if(Q[i].t == 1)
        {
            cin >> Q[i].b;
            g[Q[i].a].push_back(Q[i].b);
            g[Q[i].b].push_back(Q[i].a);
        }
    }
    for(int i = 1; i <= n; ++i) 
        if(!vis[i]) 
            chRoot(i);
    for(int i = 1; i <= n; ++i)
        for (int j = 0; (1ll<<j) < n; j++)
            P[i][j] = -1;
    for(int i = 1; i <= n; ++i)
        P[i][0] = T[i];
    for(int j = 1; (1ll<<j) < n; j++)
        for(int i = 1; i <= n; ++i)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
    for(int i = 1; i <= n; ++i)
    {
        parent[i] = i; 
        diam[i] = pair<int, int>(i, i);
    }
    for(int i = 1; i <= q; ++i)
    {
        if(Q[i].t == 1) 
            merge(Q[i].a, Q[i].b);
        else 
            cout << furthest(Q[i].a).first << endl;
    }
}
