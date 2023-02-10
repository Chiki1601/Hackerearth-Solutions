#include<bits/stdc++.h>
using namespace std;
 
int main () 
{
	  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long a[100007], sum1[100007], sum2[100007];
	  int n; 
	  cin >> n; 
	  for(int i = 0; i < n; i++) 
        cin >> a[i];
	  sort(a , a + n);
	  long long cnt = a[0], kk = 0;
	  for(int i = 1; i <= n; i++) 
    {
		    if(a[i] != a[i - 1] || i == n) 
            sum2[kk] = a[i - 1], sum1[kk++] = cnt;
		    cnt += a[i];
	  }
	  int i;
	  for(i = 0; i < kk - 1; i++) 
    {
		    if((sum1[i] == sum1[kk - 1] - sum1[i + 1]) || (sum1[i] == sum1[kk - 1] - sum1[i] && sum2[i] + 1 != sum2[i + 1])) 
        {
			      cout << "YES" << endl;
			      return 0 ;
		    }
	  }
	  cout << "NO" << endl ;
	  return 0 ;
}
