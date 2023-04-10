#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int>> v[300005];
long long int P[300005][22], sum[300005], w[300005], lvl[300005], dp1[300005][22], dp2[300005][22], n;

void dfs(long long int u, long long int p, long long int f) 
{
    lvl[u] = 1 + lvl[p];
    sum[u] = f;
    long long int c1 = sum[u] - w[u], c2 = sum[u] + w[u];
    P[u][0] = p;
    dp1[u][0] = max(c1, sum[p] - w[p]);
    dp2[u][0] = min(c2, sum[p] + w[p]);
    for(long long int i = 1; i < 22; i++) 
    {
        if(P[u][i - 1] != -1) 
        {
            P[u][i] = P[P[u][i - 1]][i - 1];
            dp1[u][i] = max(dp1[u][i - 1], dp1[P[u][i - 1]][i - 1]);
            dp2[u][i] = min(dp2[u][i - 1], dp2[P[u][i - 1]][i - 1]);
        }
    }
    for(auto i : v[u]) 
    {
        if(i.first != p) 
            dfs(i.first, u, f + i.second);
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(long long int i = 0; i <= n; i++) 
    {
        for(long long int j = 0; j < 22; j++) 
        {
            P[i][j] = -1;
            dp1[i][j] = -1e18;
            dp2[i][j] = 1e18;
        }
    }
    for(long long int i = 0; i < n - 1; i++) 
    {
        long long int x, y, l;
        cin >> x >> y >> l;
        v[x].push_back(make_pair(y, l));
        v[y].push_back(make_pair(x, l));
    }
    for(long long int i = 1; i <= n; i++) 
        cin >> w[i];
    dfs(1, 0, 0);
    long long int q;
    cin >> q;
    while(q--) 
    {
        long long int u1, v1;
        cin >> u1 >> v1;
        long long int ans = 2 * (sum[u1] - sum[v1]), dis = lvl[u1] - lvl[v1], x = -1e18, y = 1e18, node = u1;
        for(long long int i = 21; i >= 0; i--) 
        {
            if((dis - (1LL << i)) >= 0) 
            {
                x = max(x, dp1[node][i]);
                y = min(y, dp2[node][i]);
                node = P[node][i];
                dis = dis - (1LL << i);
            }
        }
        long long int c = max(0LL, x - y);
        ans -= c;
        cout << ans << "\n";
    }
    return 0;  
}
