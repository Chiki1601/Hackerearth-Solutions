#include<iostream>
#include<cmath>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		int n,b,g;
		std::cin>>n>>b>>g;
		if(std::abs(b-g)>1)
			std::cout<<"Little Jhool wins!\n";
		else
			std::cout<<"The teacher wins!\n";
	}
	return 0;
}
