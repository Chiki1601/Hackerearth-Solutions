#include<bits/stdc++.h>
using namespace std;
 
long long findDigits(long long a, long long x, long long b) 
{
	  return 1 + log(a) / log(b) + x * (log(x) / log(b)); 
}
 
int main()
{
	  long long a, n, b;
	  while(cin >> a >> n >> b) 
	  {
 		    long long low = 1, high = 1e9, mid;
 		    while(high >= low) 
		    {
			      mid = low + (high - low) / 2;
			      long long digits = findDigits(a, mid, b);
			      if(digits < n) 
				        low = mid + 1;
			      else if(digits > n) 
				        high = mid - 1;
			      else 
				        break;
		    }
		    long long count = 0;
		    low = mid;
		    for(long long i = low; ; i--) 
			      if(findDigits(a, i, b) == n) 
				        count++;
			      else 
				        break;
		        high = mid + 1;
		    for(long long i = high; ;i++) 
			      if(findDigits(a, i, b) == n) 
				        count++;
			      else 
				        break;
		        cout << count << endl;
	   }
}
