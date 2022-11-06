#include<iostream>
int main(){
	int n;
	std::cin>>n;
	long long int s=0,x;
	while(n--){
		std::cin>>x;
		s+=x;
	}
	std::cout<<s;
	return 0;
}
