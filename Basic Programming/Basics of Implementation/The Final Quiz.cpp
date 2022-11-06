#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t;
	  cin >> t;
	  for(int u = 0; u < t; u++) 
    {
		    int x, y, z, a, b, maxwins = 0, bet = -1;
		    cin >> x >> y >> z >> a >> b;
		    for(int i = 0; i <= x; i++) 
        {
			      int wins = 0;
			      for(int s = -1; s <= 1; s += 2) 
				        for(int sa = -1; sa <= 1; sa += 2) 
					          for(int sb = -1; sb <= 1; sb += 2) 
					              if (x - s * i > y - sa * a && x - s * i > z - sb * b) 
							              wins++;
			      if(wins > maxwins || bet == -1) 
            {
				        maxwins = wins;
				        bet = i;
			      }
		    }
		    cout << bet << endl;  
	  }
}
