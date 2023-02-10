#include <bits/stdc++.h>
using namespace std;
int n, A[200005];
long long k;
 
bool OK(int val)
{
	  int ptr = 1;
	  long long cnt = -n;
	  for(int i = 1; i <= n; ++i)
    {
		    while(ptr <= i && (A[i] - A[ptr]) > val) 
            ++ptr;
		    cnt += (i - ptr + 1);
	  }
	  if(cnt >= k) 
        return true;
	  else 
        return false;
}
 
int main()
{
	  cin >> n >> k;
	  for(int i = 1; i <= n; ++i) 
        cin >> A[i];
	  sort(A + 1, A + 1 + n);
	  int lo = 0, hi = 1e9, ret = hi;
	  while(lo <= hi)
    {
		    int mid = (lo + hi) / 2;
		    if(OK(mid)) 
            ret = mid, hi = mid - 1;
		    else 
            lo = mid + 1;
	  }
	  cout << ret << endl;
	  return 0;
}
