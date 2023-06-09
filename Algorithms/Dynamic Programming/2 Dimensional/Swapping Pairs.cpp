#include <bits/stdc++.h>
using namespace std;        

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1, tc = 1; 
	cin >> t;
	while(t--) 
	{
        int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n);
		vector<vector<int>> dp(n, vector<int>(k + 1));
		for(int i = 0; i < n; i++) 
			cin >> a[i] >> b[i];
		if(a[0] <= k) 
			dp[0][a[0]] = 1;
		if(b[0] <= k) 
			dp[0][b[0]] = 1;
		for(int i = 1; i < n; i++) 
		{
			for(int j = 1; j <= k; j++) 
			{
				int l = 0, r = 0;
				if(a[i] <= j) 
					l = dp[i - 1][j - a[i]];
				if(b[i] <= j) 
					r = dp[i - 1][j - b[i]];
				dp[i][j] = l || r;
			}
		}
		cout << (dp[n - 1][k] ? "YES" : "NO") << "\n";
        tc++;
    }
    return 0;
}
