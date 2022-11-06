#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.length(), r = 0, b = 0, i, flag = 1, ri, bi;
        if(n == 2)
        {
        	  cout << "2" << endl;
			      continue;
        }
        for(i = 0; i < n; i++)
        {
            if(s[i] == 'R')
           	{ 
				        r++; 
				        ri = i;
			      }           
            else
            {
				        b++;
				        bi = i;
			      }
            if(i > 0 && s[i] == s[i - 1])
            	  flag = 0;
        }
        if(s.compare("RBBBR") == 0 || s.compare("BRRRB") == 0)
        {
            cout << "3" << endl;
			      continue;
        }
        if(flag == 1 || r == 0 || b == 0)
        {
            cout << n << endl;
            continue;
        }
        if(r == 1) 
		    {
          	cout << ((ri % 3 == (n - ri - 1) % 3) ? 3 : 2) << endl;
            continue;
        }
        if (b == 1) 
		    {
            cout << ((bi % 3 == (n - bi - 1) % 3) ? 3 : 2) << endl;
            continue;
        }
        cout << "2" << endl;
    }
}
