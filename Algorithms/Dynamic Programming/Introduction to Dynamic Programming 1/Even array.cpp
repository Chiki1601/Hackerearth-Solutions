#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int t;
  	cin >> t;
  	while(t--) 
  	{
    	int n;
    	cin >> n;
    	vector<int> dp(n + 1);
    	vector<vector<int>> op(n + 1, vector<int>(2, 1000000000));
    	for(int i = 1; i <= n; i++) 
		{
      		int x; 
			cin >> x;
      		for(int j = 0; j <= 30; j++, x /= 2) 
	          	op[i][x % 2] = min(op[i][x % 2], j);
        	dp[i] = dp[i - 1] + op[i][0];
      		for(int j = i - 1; j >= max(1, i - 30); j--) 
			{
        		dp[i] = min(dp[i], dp[j - 1] + op[i][1] + op[j][1] + i - j);
        		if(op[j][1] == 0) 
					break;
      		}
    	}
    	cout << dp[n] << "\n";
  	}
  	return 0;
}
