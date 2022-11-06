#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
	  {
        int n;
        cin >> n;
        int g = 0, s = 0, b = 0, mx = 0;
        for(int i = 0; i < n; i++)
		    {
            int gtemp, stemp, btemp;
            cin >> gtemp >> stemp >> btemp;
            g += gtemp;
            s += stemp; 
            b += btemp;
            mx = max(mx, gtemp+stemp+btemp);
        }
        cout << max({mx, g, s, b}) << endl;
    }
    return 0;
}
