#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int n, w; 
    cin >> n >> w;
	  long long int work[n], sum[n+1];
	  sum[0] = {0};
	  for(int i = 0; i < n; i++) 
        cin >> work[i];
	  sort(work, work + n);
	  for(int i = 1; i <= n; i++) 
        sum[i] = sum[i - 1] + work[i - 1];
	  int maxLength = 1;
	  for(int i = 1; i < n; i++)
    {
		    int lo = 0, hi = i - 1;
		    while(lo <= hi)
        {
			      int mid = (lo + hi) / 2;
			      long long int temp = ((long long int)(i - mid)) * work[i] - (sum[i] - sum[mid]);
			      if(temp <= w)
            {
				        maxLength = max(maxLength, (i - mid + 1));
				        hi = mid - 1;
			      }
			      else 
                lo = mid + 1;
		    }
	  }
	  cout << maxLength;
	  return 0;
}
