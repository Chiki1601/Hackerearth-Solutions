#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  int t, i, x;
	  cin >> t;
	  while(t--)
	  {
		    x = 0;
		    string s = "", a = "", b = "", c = "", d = "", e = "";
		    cin >> s;
		    sort(s.begin(), s.end());
		    for(i = 0; i < s.length(); i++)
		    {
			      x = s[i]; 
			      if((x > 47) && (x < 58))
			      {
				        if(x % 2 == 1)
					          a += s[i];	
				        else
					          b += s[i];
			      }
			      else
			      {
				        if(x % 2 == 0)
					          c += s[i];
				        else
					          d += s[i];
			      }
		    }
		    e = c + d + a + b;
		    cout << e << endl;
	  }
}
