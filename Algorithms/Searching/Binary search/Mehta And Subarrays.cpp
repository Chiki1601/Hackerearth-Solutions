#include <bits/stdc++.h>
using namespace std;
 
inline void inp(long long &n)
{
    n = 0;
	  long long ch = getchar_unlocked(), sign = 1;
	  while(ch < '0' || ch > '9')
	  {
		    if(ch == '-')
			      sign = -1; 
			  ch = getchar_unlocked();
	  }
	  while(ch >= '0' && ch <= '9')
		    n = (n<<3) + (n<<1) + ch - '0', ch = getchar_unlocked();
	  n *= sign;
}
  
long long n, a[1000005];
long long check(long long len)
{
	  long long i, sum = 0, cnt = 0;
	  for(i = 0; i < len - 1; ++i)
		    sum += a[i];
	  for(i = len - 1; i <= n - 1; ++i)
	  {
		    sum += a[i];
		    if(sum >= 0) 
			      ++cnt;
			  sum -= a[i - len + 1];
	  }
	  return cnt;
}
 
long long binary()
{
	  long long st = 0, ft = n, ans = 0;
	  while(st <= ft)
	  {
		    long long mid = (st + ft) / 2;
		    if(check(mid))
		    {
			      st = mid + 1;
			      ans = mid;
		    }
		    else
			      ft = mid - 1;
	  }
	  return ans;
}
 
int main()
{
	  cin >> n;
	  for(long long i = 0; i < n; ++i) 
		    cin >> a[i];
	  long long mxlen = binary();
	  if(mxlen == 0)
	  {
		    cout << "-1";
		    return 0;
	  }
	  cout << mxlen << " " << check(mxlen);
	  return 0;
}
