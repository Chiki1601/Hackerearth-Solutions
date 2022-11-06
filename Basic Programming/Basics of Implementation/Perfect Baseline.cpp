#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t, n, k;
	  cin >> t;
	  for(int i = 0; i < t; i++)
	  {
		    cin >> n >> k;
		    string tab[n];
		    for(int j = 0; j < n; j++)
			      cin >> tab[j];
		    for(int i = 0; i < k; i++)
		    {
			      string c;
			      for(int j = 0; j < n; j++)
				        c += tab[j][i];
			      sort(c.begin(),c.end());
			      if(n % 2 == 0)
				        cout << c[n / 2 - 1];
			      else 
				        cout << c[n / 2];
		     }
		     cout << endl;
    }    
}
