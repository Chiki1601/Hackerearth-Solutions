#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
 
long long func(long long x) 
{
    int sz = primes.size();
	  long long res = 0;
	  for(int i = 1; i < 1<<sz; i++) 
	  {
 		    long long p = 1;
		    int sign = -1;
 		    for(int j = 0; j < sz; j++) 
		 	      if((i>>j) & 1) 
			      {
  				      p *= primes[j];
  				      sign *= -1;
 			      }
        res += sign * (x / p);
	  }
	  return res;
}
 
long long solve(long long k) 
{
	  long long ans = 1, lo = 1, hi = 1000000000000000000;
	  while(lo <= hi) 
	  {
 		    long long mi = (lo + hi) >> 1;
 		    if(func(mi) >= k) 
		    {
  			    ans = mi;
  			    hi = mi - 1;
 		    }    
		    else 
  			    lo = mi + 1;
	  }
	  return ans;
}
 
int main() 
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t;
	  cin >> t;
	  while(t--) 
	  {
 		    primes.clear();
 		    string s;
 		    cin >> s;
 		    long long k;
 		    cin >> k;
 		    for(int i = 0; i < s.size(); i++)
 			      if(s[i] == '1')
  				      primes.push_back(i + 1);
 		    cout << solve(k) << endl;
	  }
	  return 0;
}
