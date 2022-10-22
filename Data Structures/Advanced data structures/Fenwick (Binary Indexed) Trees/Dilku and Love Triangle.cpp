#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000001];
int BIT[1000001], Start[1000001], End[1000001], DP[20][1000001], len, level[1000001];

void update(int x, int add)
{
    for(; x < 1000001; x += x ^ (x & (x - 1)))
        BIT[x] += add;
} 

int query(int x)
{
    int ret = 0;
    for(; x > 0; x = (x & (x - 1)))
        ret += BIT[x];
    return ret;
}

void dfs(int u, int p)
{
    Start[u] = ++len;
    DP[0][u] = p;
    level[u] = level[p] + 1;
    for(int i = 0; i < (int)(g[u].size()); i++)
        if(g[u][i] != p)
            dfs(g[u][i], u);
    End[u] = len;
}

int lca(int a, int b)
{
    if(level[a] > level[b])
        swap(a,b);
    int d = level[b]-level[a];
    for(int i = 0; i < 20; i++)
        if((1<<i) & d)
            b = DP[i][b];
        if(a == b)
            return a;
    for(int i = 19; i >= 0; i--)
        if(DP[i][a] != DP[i][b])
        {
            a = DP[i][a];
            b = DP[i][b];
        }
    return DP[0][a];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= n; j++)
            DP[i][j] = DP[i - 1][DP[i - 1][j]];
            while(q--)
            {
                int t;
                cin >> t;
                if(t == 1)
                {
                    int u, v;
                    cin >> u >> v;
                    int LCA = lca(u, v);
                    update(Start[u], +1);
                    update(Start[v], +1);
                    update(Start[LCA], -1);
                    if(LCA != 1)
                        update(Start[DP[0][LCA]], -1);
                }
                else if(t == 2)
                {
                    int x;
                    cin >> x;
                    cout << query(End[x]) - query(Start[x] - 1) << endl;
                }
            }
    return 0;
}
