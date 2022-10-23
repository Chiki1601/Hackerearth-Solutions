#include<bits/stdc++.h>
using namespace std;
 
#define lli long long int
 
int main()
 
{
 
   ios_base::sync_with_stdio(0);
 
   cin.tie(0);
 
   cout.tie(0);
 
   lli t,n,i;
 
   cin>>t;
 
   while(t--)
 
   {
 
      cin>>n;
 
      lli a[n];
 
      for(i=0;i<n;i++)
 
      cin>>a[i];
 
      if(n==1)
 
      cout<<a[0]<<"\n";
 
else
 
      {
 
         lli lc=(a[0]*a[1])/(__gcd(a[0],a[1]));
 
for(i=2;i<n;i++)
 
      {
 
       lc=(lc*a[i])/(__gcd(lc,a[i]));   
 
      }
 
      cout<<lc<<"\n";
 
      }
 
   }
 
return 0;
 
}
