#include<iostream>
#include<algorithm>
#include<set>
int main(){
	int mx=0,mn=100,n,x,r;
	std::cin>>r;
	n=r;
	std::set<int> arr;
	while(r--){
		std::cin>>x;
		arr.insert(x);
		if(x<mn)
			mn=x;
		else if(x>mx)
			mx=x;
	}
	if(mx-mn+1==arr.size())
		std::cout<<"YES";
	else
		std::cout<<"NO";
	return 0;
}	
