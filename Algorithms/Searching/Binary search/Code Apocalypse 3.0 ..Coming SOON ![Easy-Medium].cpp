#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  long long int t; 
	  cin >> t;
	  while(t--)
	  {
		    long long int n, m, x, y; 
		    cin >> n >> m >> x >> y;
		    long long int l = 0, r = n, mid, ans;
		    while(l <= r)
		    {
			      mid = l + (r - l) / 2;
			      long long int temp = m + mid * y, g = temp / x;
			      if(g >= n - mid)
			      {
				        ans = mid;
				        r = mid - 1;
			      }
			      else
				        l = mid + 1;
		    }
		    cout << n - ans << endl;
	  }
	  return 0;
}
