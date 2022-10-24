#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
    cin >> t;
    while(t--)
    { 
		string s, t;
      	cin >> s >> t;
     	int f = 1, ans = -1;
     	for(int i = 0; i < s.size(); i++)
     	{   
		 	int diff = ((t[i] - s[i]) + 26) % 26;
            if(ans == -1)
            	ans = diff;
          	else if(ans == diff)
           		continue;
           	else
      		{     	
				f = 0;
            	break;
        	}  
        }
		if(f)
      		cout << ans << endl;
      	else
      		cout << -1 << endl;
    }
}
