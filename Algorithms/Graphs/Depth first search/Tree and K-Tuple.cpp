#include <bits/stdc++.h>
using namespace std;
long long n, k, ans, BIT[100005][25], a[100005], dp[100005][25];
vector<vector<long long>> AdjList(100005);
 
void update(long long x, long long type, long long val)
{
    while(x < 100005)
    {
        BIT[x][type] += val;
        x += x & -x;
    }
}
 
long long get(long long x, long long type)
{
    long long res = 0;
    while(x > 0)
    {
        res += BIT[x][type];
        res %= 1000000007;
        x -= x & -x;
    }
    return res;
}
 
void DFS(long long u, long long parent)
{
    dp[u][0] = 1;
    for(long long i = 1; i <= k; i++)
    {
        dp[u][i] = (get(100000, i - 1) - get(a[u], i - 1)) % 1000000007;
    }
    ans += dp[u][k];
    ans %= 1000000007;
    for(long long i = 0; i <= k; i++)
        update(a[u], i, dp[u][i]);
    for(long long v : AdjList[u])
    {
        if(v != parent)
            DFS(v, u);
    } 
    for(long long i = 0; i <= k; i++)
        update(a[u], i, -dp[u][i]);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(long long i = 1; i <= n; i++)
        cin >> a[i];
    for(long long i = 1; i < n; i++)
    {
        long long u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    DFS(1, 1);
    cout << (ans + 1000000007) % 1000000007;
}
