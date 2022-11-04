#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long test = 0, dp[600][2000];
    cin >> test;
	vector<vector<pair<long long, pair<long long, long long>>>> v(600); 
    while(test--)
    {
		long long n, m, B, query;
		cin >> n >> m >> B;
		for(int i = 0; i <= n; i++)
			v[i].clear();
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= B; j++)
				dp[i][j] = (1LL << 60) - 1;
		for(int i = 0; i < m; i++)
		{
			long long a, b, c, d;
			cin >> a >> b >> c >> d;
			v[a].push_back({b, {c, d}});
		}
		queue<pair<long long, pair<long long, long long>>> q;
		q.push({1, {0, 0}});
		dp[1][0] = 0;
		while(!q.empty())
		{
			long long node = q.front().first, cost = q.front().second.first, dist = q.front().second.second;
			q.pop();
			for(auto x : v[node])
			{
				long long node_ = x.first, cost_ = x.second.first, dist_ = x.second.second;
				if(cost_ + cost > B)
					continue;
				dp[node_][cost_ + cost] = min(dp[node_][cost_ + cost], dp[node_][cost_ + cost - 1]);
				if(dp[node][cost] + dist_ < dp[node_][cost_ + cost])
				{
					dp[node_][cost_ + cost] = dp[node][cost] + dist_;
					q.push({node_, {cost_ + cost, dp[node_][cost_ + cost]}});
				}
			}
		}
		for(int i = 1; i <= n; i++)
			for(int c = 1; c <= B; c++)
				dp[i][c] = min(dp[i][c], dp[i][c - 1]);
		cin >> query;
		while(query--)
		{
			long long dest, budget;
			cin >> dest >> budget;
			cout << (dp[dest][budget] == (1LL << 60) - 1 ? -1 : dp[dest][budget]) << endl;
		}
	}
    return 0;
}
