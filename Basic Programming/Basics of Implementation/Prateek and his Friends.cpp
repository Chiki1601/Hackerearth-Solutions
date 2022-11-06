#include<iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    long n,i,j;
    std::cin>>t;
    while(t--){
		long long int sum,s;
		bool flag=false;
		std::cin>>n>>sum;
		long int a[n];
		for(i=0;i<n;i++)
			std::cin>>a[i];
		for(i=0;i<n;i++){
            j=i,s=0;
			while(s<sum && j<n){
				s+=a[j];
				if(s==sum){
					flag=true;
					break;
				}
				j++;
			}
		}
		if(flag)
			std::cout<<"YES\n";
		else
			std::cout<<"NO\n";
    }
    return 0;
}
