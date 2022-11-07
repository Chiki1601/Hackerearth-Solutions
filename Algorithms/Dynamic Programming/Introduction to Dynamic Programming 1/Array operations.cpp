#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int T; 
	cin >> T; 
	while(T--)
    {
      	long long int n, sum = 0; 
		cin >> n;
      	vector<long long int>a(n);
      	for(auto &it : a) 
		  	cin >> it;
      	vector<long long int>pre(n, 0), suff(n, 0);
      	for(long long int i = 0; i < n; i++)
		{
          	sum += a[i];
          	pre[i] = max(sum, pre[i]);
          	sum = max(sum, 0ll);
      	}
      	sum = 0;
      	for(long long int i = n - 1; i >= 0; i--)
		{
          	sum += a[i];
          	suff[i] = max(suff[i], sum);
          	sum = max(sum, 0ll);
      	}
      	long long int ans = 0, best = 0;
      	for(long long int i = 0; i < n; i++)
	  	{
          	ans = max(ans, best + suff[i]);
          	best = max(best, pre[i]);
      	}
      	ans = max(ans, best);
      	cout << ans << endl;
    }
	return 0;
}
