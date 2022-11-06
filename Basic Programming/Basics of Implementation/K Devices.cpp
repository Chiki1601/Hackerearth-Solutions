#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int n,k,i,ans,j;
	scanf("%lld %lld",&n,&k);
		long long int x[n],y[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x[i]);
		
		}
			for(i=0;i<n;i++)
		{
			scanf("%lld",&y[i]);
		
		}
		double d[n];
for(j=0;j<n;j++)	
		d[j]= x[j]*x[j] + y[j]*y[j] ;
	sort(d,d+n);
	ans = ceil(sqrt(d[k-1]) );
	
	printf("%lld",ans);
	return 0;
 
}
