#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    assert(1 <= t && t <= 10);
    while(t--)
    {
        int n, m, i;
        cin >> n >> m;
        assert(2 <= n && n <= 100000);
        assert(1 <= m && m <= 100000);
        vector<pair<long long int, long long int>> g[n + 1];
        for(i = 0; i < m; i++)
        {
            int l, r, w;
            cin >> l >> r >> w;
            assert(1 <= l && l <= n);
            assert(1 <= r && r <= n);
            assert(1 <= w && w <= 1000000000);
            assert(l < r);
            g[l].push_back({r, w});
        }
        for(i = 2; i <= n; i++)
            g[i].push_back({i - 1, 0});
        int vis[n + 1] = {0};
        long long int dp[n + 1];
        for(i = 1; i <= n; i++)
                dp[i] = 1000000000000000000;
        dp[1] = 0;
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> q;
        q.push({0, 1});
        while(q.size() != 0)
        {
            int s = q.top().second;
            q.pop();
            if(vis[s] == 1)
                continue;
            vis[s] = 1;
            for(auto u : g[s])
            {
                if(dp[u.first] > dp[s] + u.second)
                {
                    dp[u.first] = dp[s] + u.second;
                    q.push({dp[u.first], u.first});
                }
            }
        }
        if(dp[n] == 1000000000000000000)
            cout << -1 << endl;
        else
            cout << dp[n] << endl;
    }
}
