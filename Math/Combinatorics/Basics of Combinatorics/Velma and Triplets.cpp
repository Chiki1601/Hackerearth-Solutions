#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll mpp[4];
 
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n,res=0; cin>>n;
  for(int i=0;i<n;++i){ ll x; cin>>x; if(x<4) mpp[x]++; }
  ll a=mpp[1],b=mpp[2],c=mpp[3],d=n-a-b-c;
  res = (a*(a-1)*(a-2))>>1;
  res += a*(a-1)*b;
  res += ((a*(a-1))>>1)*(d+c);
  res += ((b*(b-1))>>1)*a;
  res += a*b*c;
  cout<<res;
  return 0;
}
