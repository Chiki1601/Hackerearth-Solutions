#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) 
	{
		int n, k, l = -1, r = 1000000000;
		cin >> n >> k;
		vector<vector<int>> a(2, vector<int>(n));
		for(int i = 0; i < 2; i++) 
		{
			for(int j = 0; j < n; j++) 
				cin >> a[i][j];
		}
		while(r - l > 1) 
		{
			int mid = (l + r) / 2;
			vector<int> dp(2);
			for(int i = 1; i < n; i++) 
			{
				vector<int> ndp(2, k + 1);
				for(int j = 0; j < 2; j++) 
					for(int k = 0; k < 2; k++) 
						if(abs(a[j][i - 1] - a[k][i]) <= mid) 
							ndp[k] = min(ndp[k], dp[j] + k);
				dp = ndp;
			}
			(min(dp[0], dp[1]) <= k) ? r = mid : l = mid;
		}
		cout << r << "\n";
	}
	return 0;
}
