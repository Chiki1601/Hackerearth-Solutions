#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  long long n;
	  cin >> n;
	  long long A[n], P[n];
	  for(long long i = 0; i < n; i++)
        cin >> A[i];
	  sort(A, A + n);
	  P[0] = A[0];
	  for(long long i = 1; i < n; i++)
        P[i] = P[i - 1] + A[i];
	  for(long long i = 0; i < n; i++)
        P[i] /= (i + 1);
	  long long q;
	  cin >> q;
	  while(q--)
    {
		    long long k, ans = 0, l = 0, h = n - 1;
		    cin >> k;
		    while(l <= h)
        {
			      long long mid = l + (h - l) / 2;
			      if(P[mid] < k)
            {
                ans = mid + 1;
			          l = mid + 1;
            }
			      else 
                h = mid - 1;
		    }
		    cout << ans << endl;
    }
}
