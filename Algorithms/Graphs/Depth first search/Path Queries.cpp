#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int> , null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
int cur, LVL[40005], DP[19][40005], BL[40005 << 1], ID[40005 << 1], l[40005], r[40005];
long long int A[40005], ANS[100005];
bool VIS[40005];
vector<int> adjList[40005];
ordered_set o;
 
struct query
{
    int id, l, r, lc, k;
    bool operator < (const query& rhs)
    {
        return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
    }
}Q[100005];
 
void dfs(int u, int par)
{
    l[u] = ++cur;
    ID[cur] = u;
    for(int i = 1; i < 19; i++) 
        DP[i][u] = DP[i - 1][DP[i - 1][u]];
    for(int i = 0; i < adjList[u].size(); i++)
    {
        int v = adjList[u][i];
        if(v == par) 
            continue;
        LVL[v] = LVL[u] + 1;
        DP[0][v] = u;
        dfs(v, u);
    }
    r[u] = ++cur; 
	ID[cur] = u;
}
 
inline int lca(int u, int v)
{
    if(LVL[u] > LVL[v]) 
        swap(u, v);
    for(int i = 18; i >= 0; i--)
        if(LVL[v] - (1 << i) >= LVL[u]) 
            v = DP[i][v];
    if(u == v) 
        return u;
    for(int i = 18; i >= 0; i--)
    {
        if(DP[i][u] != DP[i][v])
        {
            u = DP[i][u];
            v = DP[i][v];
        }
    }
    return DP[0][u];
}
 
inline void check(int x, int& res)
{
    if((VIS[x]))
    {
        res--;
        o.erase(make_pair(A[x], x));
    }
    else if((!VIS[x])) 
    {
        res++;
        o.insert(make_pair(A[x], x));
    }
    VIS[x] ^= 1;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, u, v, x, k, N, q;
    t = 1;
    while(t--)
    {
        cin >> N >> q;
        cur = 0;
        memset(VIS, 0, sizeof(VIS));
        for(int i = 1; i <= N; i++) 
            adjList[i].clear();
        for(int i = 1; i <= N; i++) 
            cin >> A[i];
        for(int i = 1; i < N; i++)
        {
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        DP[0][1] = 1;
        dfs(1, -1);
        int size = sqrt(cur);
        for(int i = 1; i <= cur; i++) 
            BL[i] = (i - 1) / size + 1;
        for(int i = 0; i < q; i++)
        {
            cin >> u >> v;
            Q[i].lc = lca(u, v);
            Q[i].k = -1;
            if(l[u] > l[v]) 
                swap(u, v);
            if(Q[i].lc == u) 
            {
                Q[i].l = l[u]; 
                Q[i].r = l[v];
            }
            else
            { 
                Q[i].l = r[u]; 
                Q[i].r = l[v];
            }
            Q[i].id = i;
        }
        sort(Q, Q + q);
        int curL = Q[0].l, curR = Q[0].l - 1, res = 0;
        for(int i = 0; i < q; i++)
        {
            while(curL < Q[i].l) 
                check(ID[curL++], res);
            while(curL > Q[i].l) 
                check(ID[--curL], res);
            while(curR < Q[i].r) 
                check(ID[++curR], res);
            while(curR > Q[i].r) 
                check(ID[curR--], res);
            int u = ID[curL], v = ID[curR];
            if(Q[i].lc != u and Q[i].lc != v) 
                check(Q[i].lc, res);
            int size = o.size();
            pair<int, int> minimum = *(o.find_by_order(0)), median = *(o.find_by_order((size+1)/ 2 - 1)), maximum = *(o.find_by_order(size - 1));
            ANS[Q[i].id] = minimum.first + median.first + maximum.first;
            if(Q[i].lc != u and Q[i].lc != v) 
                check(Q[i].lc, res);
        }
        for(int i = 0; i < q; i++) 
            cout << ANS[i] << " ";
        cout << "\n";
    }
}
