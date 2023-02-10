#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int is_increasing(int arr[], int n)
{
   	for(int i = 1; i < n; i++)
	  {
       	if(arr[i]<=arr[i-1])    
	   		    return 0;
   	}
   	return 1;
}
 
int evaluate(int n, int ar[], int k)
{
   	int arr[n];
   	for(int i = 0; i < n; i++)  
   		  arr[i]=ar[i];
   	arr[0] = max(1LL, arr[0] - k);
   	for(int i = 1;i < n; i++)
	  {
       	if(arr[i] > arr[i - 1])
           	arr[i] = max(arr[i - 1] + 1, arr[i] - k);
       	else
           	arr[i] = min(arr[i - 1] + 1, arr[i] + k);
   	}
   	if(is_increasing(arr, n))    
	   	  return 1;
   	else    
   		  return 0;
}
 
signed main()
{
   	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   	int t;
   	cin >> t;
   	while(t--)
	  {
       	int n, ans;
       	cin >> n;
       	int arr[n], lo = 0, hi = 1e9;
       	for(int i = 0; i < n; i++)  
		   	    cin >> arr[i];
       	while(lo <= hi)
		    {
           	int mid = (lo + hi) / 2;
           	int bac = evaluate(n, arr, mid);
           	if(bac == 1)
			      {
               	ans = mid;
               	hi = mid - 1;
           	}
           	else
               	lo = mid + 1;
       	}
       	cout << ans << endl;
   	}
}
