#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
	 cin.tie(0); cout.tie(0);
	 long n;
   cin >> n;
   int w[n], h[n], i, widthsum = 0, temph[n], currentwidthsum = 0;
   for(i = 0; i < n; i++)
   {
      cin >> w[i] >> h[i];
      temph[i] = h[i];
      widthsum = widthsum + w[i];
   }
   sort(temph, temph + n);
   for(i = 0; i < n; i++)
   {
      currentwidthsum = widthsum - w[i];
      if(h[i] != temph[n - 1])
         cout << temph[n - 1] * currentwidthsum << " ";
      else
         cout << temph[n - 2] * currentwidthsum <<" ";
   }
   return 0;
}
