#include<bits/stdc++.h>
using namespace std;
 
bool isPrime(int n)
{
	  if(n <= 1) 
		    return false;
	  for(int i = 2; i <= (int)sqrt(n); i++) 
		    if(n % i == 0) 
			      return false;
	  return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; 
	  cin >> n >> k;
    int arr[n], sum[n + 1];
    sum[0] = {0};
    for(int i = 0; i < n; i++) 
	  {
    	  cin >> arr[i];
    	  arr[i] = isPrime(arr[i]);
    	  sum[i + 1] = sum[i] + arr[i];
    }
	  long long ans = 0;
	  for(int i = 0; i < n - 1; i++)
	  {
		    int maxx = i + 1, lo = i + 2, hi = n;
		    while(lo <= hi)
		    {
			      int mid = (lo + hi) / 2;
			      if((sum[mid] - sum[i + 1]) <= (k - arr[i]))
			      {
				        maxx = max(maxx, mid);
				        lo = mid + 1;
			      }
			      else 
				        hi = mid -1;
		    }
		    ans += (maxx - i);
	  }
	  cout << ++ans;
	  return 0;
}
