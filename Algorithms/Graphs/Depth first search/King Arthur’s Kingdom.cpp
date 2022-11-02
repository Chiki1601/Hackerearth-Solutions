#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;
long long val[20], cnt;
set<long long> s;
 
void dfs(long long mask, long long u, long long par) 
{
    s.insert(val[u]);
    cnt++;
    for(auto to : g[u]) 
    {
        if(par != to && (mask & (1ll<<(to - 1)))) 
            dfs(mask, to, u);
    }
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) 
    {
        int n, k;
        cin >> n >> k;
        g.resize(n + 1);
        for(int j = 1; j <= n; ++j) 
        {
            cin >> val[j];
            g[j].clear();
        }
        for(int j = 1; j < n; ++j) 
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }    
        long long ans = 0;
        for(long long mask = 0; mask < (1ll<<n); ++mask) 
        {  
            long long sz = 1000000000000000000, setBits = __builtin_popcount(mask);
            for(long long j = 0; j < n; ++j) 
            {   
                if(mask & (1<<j)) 
                {
                    cnt = 0;
                    s.clear();
                    dfs(mask, j + 1, 0);
                    if(cnt == setBits)  
                        sz = s.size();
                    break;
                }
            }
            if(sz <= k) 
                ans++;
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
