#include<iostream>
#include<string>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t,n,i;
	std::cin>>t;
	while(t--){
		char ch='a';
		std::cin>>n;
		int arr[n];
		for(i=0;i<n;i++)
			std::cin>>arr[i];
		if(arr[0]>1){
			std::cout<<"-1\n";
			continue;
		}
		std::string st="a";
		for(i=1;i<n;i++){
			if(arr[i]>i+1 || arr[i]<arr[i-1] || arr[i]-arr[i-1]>1){
				st="-1";
				break;
			}
			else if(arr[i]==arr[i-1])
				st+="a";
			else
			    st+=(++ch);
		}
		std::cout<<st<<"\n";
	}
	return 0;
}
