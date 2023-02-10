#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
	  cin >> t;
    while(t--)
	  {
        long long int a, b, c, d, k, l = 1, h = 900000, ans = 0;
        cin >> a >> b >> c >> d >> k;
        while(l <= h) 
		    {
            long long int mid = l + (h - l) / 2;
            long long int val = a * mid * mid * mid + b * mid * mid + c * mid + d;
            if(val <= k)
			      {
                ans = mid;
                l = mid + 1;
            }
            else 
				        h = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
