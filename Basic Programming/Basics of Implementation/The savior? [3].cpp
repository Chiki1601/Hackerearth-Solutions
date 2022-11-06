#include<iostream>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	long t,n,x,i,j,c=0;
	std::cin>>t;
	while(t--){
		std::cin>>n;
		long a[n];
		for(i=0;i<n;i++)
			std::cin>>a[i];
		for(i=0,c=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(a[i]!=a[j] && (a[i]&1)==(a[j]&1))
					c++;
		std::cout<<c<<"\n";
	}
	return 0;
}
