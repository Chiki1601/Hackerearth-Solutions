#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  long long n, q; 
	  cin >> n >> q;
	  long long arr[n];
	  for(long long i = 0; i < n; i++)
		    cin >> arr[i];
	  long long a[n] = {}; 
	  for(long long i = 0; i < n; i++)
		    a[i] = __builtin_popcount(arr[i]); 
	  long long p[n + 1] = {}, sum = 0;
	  for(long long i = 0; i < n; i++)
  	{
		    sum += a[i];
		    p[i + 1] = sum;
	  }
	  while(q--)
	  {
		    long long x, res = 0, mini = LLONG_MAX; 
		    cin >> x;
		    for(long long i = 1; i < n + 1; i++)
		    {
			      long long low = lower_bound(p, p + n + 1, x + p[i - 1]) - p;
			      if(low < n + 1)
			      {
				        res = low - i + 1;
				        if(res < -1) 
					          mini = 1;
				        else
					          mini = min(mini, res);
			      }
		    }
		    if(mini > n) 
			      cout << "-1" << endl;
		    else 
			      cout << mini << endl;
	  }
}
