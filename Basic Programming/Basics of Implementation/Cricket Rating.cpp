#include<iostream>
#include<algorithm>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	long n,r,s=0,mx=0;
	std::cin>>n;
	while(n--){
		std::cin>>r;
		mx=std::max((long)0,r+mx);
		s=std::max(s,mx);
	}
	std::cout<<s;
	return 0;
}
