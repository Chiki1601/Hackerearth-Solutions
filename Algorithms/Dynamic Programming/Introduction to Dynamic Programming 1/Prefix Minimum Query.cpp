#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	vector<vector<long long>> nxt(n + 1, vector<long long>(20, n)), dp(n + 1, vector<long long>(20));
	vector<int> v;
	for(int i = n - 1; i >= 0; i--) 
	{
		while(v.size() && a[v.back()] >= a[i]) 
			v.pop_back();
		nxt[i][0] = (v.size() > 0) ? v.back() : n;
		dp[i][0] = 1LL * a[i] * (nxt[i][0] - i);
		for(int j = 1; j < 20; j++) 
		{
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
			dp[i][j] = dp[i][j - 1] + dp[nxt[i][j - 1]][j - 1];
		}
		v.push_back(i);
	}
	while(q--) 
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		long long ans = 0;
		for(int i = 19; i >= 0; i--) 
		{
			if(nxt[l][i] - 1 <= r) 
			{
				ans += dp[l][i];
				l = nxt[l][i];
			}
		}
		ans += 1LL * a[l] * (r - l + 1);
		cout << ans << "\n";
	}
}
