#include <bits/stdc++.h>
using namespace std;
int dp[362980][10];
 
int main() 
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<int> vv;
	for(int i = 0; i < 9; ++i)
		vv.push_back(i);
	int cnt = 0, tt;
	map<vector<int>, int> mm;
	do 
	{
		mm[vv] = cnt++;
	} 
	while(next_permutation((vv).begin(), (vv).end()));
	vv.clear();
	for(int i = 0; i < 9; ++i)
		vv.push_back(i);
	for(int i = 0; i < 9; ++i)
		dp[0][i] = 1;
	next_permutation((vv).begin(), (vv).end());
	for(int i = 1; i < cnt; ++i, next_permutation((vv).begin(), (vv).end())) 
	{
		for(int j = 7; j >= 0; --j) 
		{
			dp[i][j] = dp[i][j + 1];
			if(vv[j] > vv[j + 1]) 
			{
				swap(vv[j], vv[j + 1]);
				int y = mm[vv];
				swap(vv[j], vv[j + 1]);
				dp[i][j] += dp[y][max(0, j - 1)];
				if(dp[i][j] >= 1000000007)
					dp[i][j] -= 1000000007;
			}
		}
	}
	cin >> tt;
	for(int i = 0; i < tt; ++i)
	{
		int n;
		cin >> n;
		vector<int> vv;
		for(int i = 0; i < n; ++i) 
		{
			int x;
			cin >> x;
			vv.push_back(x - 1);
		}
		while(vv.size() < 9)
			vv.push_back(vv.size());
		int x = mm[vv];
		cout << dp[x][0] << endl;
	}
	return 0;
}
