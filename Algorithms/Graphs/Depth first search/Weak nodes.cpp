#include<bits/stdc++.h>
using namespace std;
long long n, m, vis[500100], disc[500100], low[500100], power[500100], tim=0, isap[500100] = {0};
vector<long long> v[500100], ap;

void solve(long long x, long long prev)
{
    vis[x] = 1;
    disc[x] = low[x] = ++tim;
    int child = 0;
    for(int i = 0; i < v[x].size(); i++)
    {
        if(v[x][i] != prev)
        {
            if(!vis[v[x][i]])
            {
                child++;
                solve(v[x][i], x);
                low[x] = min(low[x], low[v[x][i]]);
                if(prev == -1 && child > 1 && !isap[x])
                {
                    isap[x] = 1;
                    ap.push_back(x);
                }           
                else if(prev != -1 && low[v[x][i]] >= disc[x] && !isap[x])
                {
                    isap[x] = 1;
                    ap.push_back(x);
                }
            }
            else
                low[x] = min(low[x], disc[v[x][i]]);
        }
    }
}
 
long long POWER(long long a, long long b, long long mod)
{
    long long ret = 1;
    while(b)
    {
        if(b & 1) 
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    long long i, j, k, arr[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23}, f[600] = {0}, dp[2][10000] = {0}, c = 1, p = 0;
    for(i = 1; i <= n; i++)
        cin >> power[i];
    for(i = 0; i < m; i++)
    {
        long long x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
            solve(i, -1);
    }
    for(i = 0; i < ap.size(); i++)
    {
        long long temp = 0;
        for(j = 0; j < 9; j++)  
            if(power[ap[i]] % arr[j] == 0)
                temp |= (1<<j);
        f[temp]++;  
    }
    for(i = 0; i < 512; i++)
        f[i] = (POWER(2, f[i], 1000000007) - 1 + 1000000007) % 1000000007;
    for(i = 0; i < 512; i++)
    {
        long long temp = f[i];
        for(j = 0; j < 512; j++)
            dp[c][j] = dp[p][j];    
        for(j = 0; j < 512; j++)
            dp[c][j|i] = (dp[c][j|i] + ((dp[p][j] * temp) % 1000000007)) % 1000000007; 
        dp[c][i] = (dp[c][i] + temp) % 1000000007;
        c = !c;
        p = !p;
    }           
    cout << dp[p][511] << endl;
    return 0;
}
