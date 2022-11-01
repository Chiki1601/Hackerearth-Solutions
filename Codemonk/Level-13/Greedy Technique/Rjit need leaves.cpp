#include<bits/stdc++.h>
using namespace std;

int main() 
{
  	int tc;
  	cin >> tc;
  	while (tc--) 
	{
  		int n, k, ans = 0;
    	cin >> n >> k; 
    	unordered_map <int, int> mp;
    	for(int i = 0; i < n; i++) 
		{
      		int a;
      		cin >> a;
      		if(mp[a + 1] == 0)
        		ans++;
      		else
        		mp[a + 1] --;
      		mp[a]++;
    	} 
    	if(k - ans < 0)
      		puts("-1");
    	else
      		cout << k - ans << endl;
  	}
  	return 0;
} 
