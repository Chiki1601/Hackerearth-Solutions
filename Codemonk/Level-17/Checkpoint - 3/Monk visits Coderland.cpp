#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int tc;
  	cin >> tc;
  	while(tc--)
  	{
    	int n;
    	cin >> n;
    	long long c[n + 1], l[n + 1];
    	for(int i = 1; i <= n; i++)
      		cin >> c[i];
    	for(int i = 1; i <= n; i++)
      		cin >> l[i];
    	long long mi = 1000000LL, ans = 0;
    	for(int i = 1; i <= n; i++)
   	 	{
     		mi = min(mi, c[i]);
      		ans += mi * l[i];
    	}
    	cout << ans << "\n";
  	}
  	return 0;
}
