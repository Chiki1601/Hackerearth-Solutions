#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int t; 
	cin >> t; 
	while(t--)
    {
      	long long int n; 
	  	cin >> n;
      	vector<long long int>a(n);
      	for(auto &it : a) 
	  		cin >> it;
      	vector<bool>dp(10002, false);
      	dp[0] = true;
      	for(int i = 0; i < n; i++)
	  	{
          	for(int j = 10001; j >= 0; j--)
		  	{
              	if(j - a[i] >= 0 && dp[j - a[i]])
                  	dp[j] = true;
          	}
      	}
      	vector<long long int>ans(n, 0);
      	for(int i = 0; i < n; i++)
	  	{
          	if(a[i] == 1)
              	ans[i] = 1;
          	else
		  	{
              	long long int x = a[i] * a[i];
              	while(x < 10002)
			  	{
                  	if(dp[x])
                      	ans[i] = 1;
                  	x *= 2;
             	}
          	}
      	}
      	for(auto it : ans)
          	cout << it << " ";
      	cout << endl;
    }
	return 0;
}
