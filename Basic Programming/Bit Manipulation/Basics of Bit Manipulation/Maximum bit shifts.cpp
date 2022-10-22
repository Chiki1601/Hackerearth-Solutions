#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 	  int t;
 	  cin >> t;
 	  while(t--)
 	  {
 		    unsigned long long num, cnt = 0, ans = 0, maxbit = 0;
 		    cin >> num;
 		    maxbit = log2(num);
 		    while(num)
 		    {
 			      if(num & 1)
 				        cnt++;
 			      num>>=1;
 		    }
 		    while(cnt--)
 		    {
 			      ans |= (1ULL <<(maxbit));
 			      maxbit--;
 		    }
 		    cout << ans << " ";
 	  }
}
