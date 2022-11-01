#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int t, arr[16]; 
  	cin >> t;
  	while(t--)
  	{
    	string predict; 
		cin >> predict; 
		int ans, k, n, mx = 0; 
		cin >> n;
    	for(int i = 0; i < n; ++i) 
			cin >> arr[i];
    	for(int i = 0; i < (1<<n); ++i)
		{
      		ans = k = 0;
      		for(int j = 0; j < n; ++j)
	  		{
        		if(i & (1<<j))
				{
          			if(k % 3 == 0) 
		  				ans += arr[j];
          			else if(k % 3 == 1) 
		  				ans |= arr[j];
          			else 
		  				ans ^= arr[j];
          			k++;
        		}
      		}
      		mx = max(mx, ans);
    	}
    	((mx & 1) ^ (predict == "Odd")) ? cout << "Mariam\n" : cout << "Monk\n";
  	}
  	return 0;
}
