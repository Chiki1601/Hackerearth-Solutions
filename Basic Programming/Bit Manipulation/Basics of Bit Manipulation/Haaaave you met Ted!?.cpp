#include<bits/stdc++.h>
using namespace std;
 
int main()
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned int t, n, ans, x;
    cin >> t;
    while(t--)
	  {
    	  cin >> n;
    	  for(int i = 0; i < n; i++)
		    {    
        	  cin >> x;
         	  if(i == 0)
        		    ans = __builtin_popcount(x);
        	  else if(__builtin_popcount(x)<ans)
        		    ans = __builtin_popcount(x);
    	  }
    	  cout << ans << endl;
    }
}
