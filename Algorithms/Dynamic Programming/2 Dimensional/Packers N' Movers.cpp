#include<bits/stdc++.h>
using namespace std;
int dp[16][251];
 
int ans(int v[], int n, int m, int i = 0)
{
  	if(i == n)
    	return 0;
  	if(m == 0)
    return INT_MAX;
  	if(dp[m][i] != -1) 
	  	return dp[m][i];
  	int res = INT_MAX, s = 0;
  	res = ans(v, n, m - 1, i);
  	for(int h = i; h < n; h++)
	{
    	s += v[h];
    	res = min(res, max(s, ans(v, n, m - 1, h + 1)));
  	}
  	return dp[m][i] = res;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int m, n;
  	cin >> m >> n;
  	int v[n];
  	for(int h = 0; h < n; h++)
    	cin >> v[h];
  	memset(dp, -1, sizeof(dp));
  	cout << ans(v, n, m) << endl;
}
