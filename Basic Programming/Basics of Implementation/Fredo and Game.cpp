#include<iostream>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		int a,n,i,pos=-1;
		std::cin>>a>>n;
		for(int j=1;j<=n;j++){
			std::cin>>i;
			if(a>0){
                		a=a+3*i-1;
				if(!a and n^j)
				    pos=j;
			}
		}
		if(pos==-1)
			std::cout<<"Yes "<<a<<"\n";
		else
			std::cout<<"No "<<pos<<"\n";
	}
	return 0;
}
