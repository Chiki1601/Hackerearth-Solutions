#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
	  long long n;
	  double p = 0;
	  cin >> n;
	  long long arr[n];
	  for(long long i = 0; i < n; i++)
        cin >> arr[i];
	  sort(arr, arr + n);
	  for(int i = 0; i < n; i++)
    	  p += log10(arr[i]);
	  long long l, h;
	  l = 0;
	  h = arr[n - 1] + 1;
	  long long mid, ans;
	  while(l <= h)
	  {
 		    mid = (l + h) / 2;
        if(p >= (n * log10(mid)))
			      l = mid + 1;
		    if(p < (n * log10(mid)))
		    {
			      h = mid - 1;
			      ans = mid;
		    }
	  }
	  cout << ans;
}
