#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ar[5005], pre[5005], dp[5005];
	cin >> n;
	assert(n <= 5000);
	vector<int> v;
	bool vis[5005];
	for(int i = 1; i <= n; i++) 
	{
		cin >> ar[i];
		assert(ar[i] <= 100000);
		pre[i] = pre[i - 1] + ar[i];
	}
	v.push_back(2);
	for(int i = 3; i < 5005; i += 2) 
		if(!vis[i]) 
		{
			v.push_back(i);
			for(int j = i * i; j < 5005; j += 2 * i) 
				vis[j] = true;
		}
	dp[0] = dp[1] = 0;
	for(int i = 2; i <= n; i++) 
	{
		dp[i] = dp[i - 1];
		for(int j = 0; j < (int)v.size() and v[j] <= i; j++) 
		{
			int p = i - v[j] - 1;
			if(p == -1) 
				dp[i] = max(dp[i], pre[i]);
			else 
				dp[i] = max(dp[i], dp[p] + pre[i] - pre[p + 1]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
