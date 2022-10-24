#include <bits/stdc++.h>
using namespace std;
 
long long sum(long long n)
{
	  long long ret = 0;
	  while(n)
	  {
		    ret = ret + n % 16;
		    n /= 16;
	  }
	  return ret;
}
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  long long t;
	  cin >> t;
	  while(t--)
	  {  
		    long long cnt = 0, l, r;
		    cin >> l >> r;
		    for(long long i = l; i <= r; i++)
		    {
			      if(__gcd(i, sum(i)) > 1)
				        cnt++;
		    }
		    cout << cnt << endl;
	  }
	  return 0;
}
