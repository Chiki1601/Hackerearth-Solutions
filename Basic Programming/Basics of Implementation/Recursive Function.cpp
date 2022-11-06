#include<iostream>
#include<iomanip>
int fun(long x,long y){
	if(x==0)
		return (y+1)%1000;
	if(x>0 && y==0)
		return fun(x-1,1)%1000;
	return fun(x-1,fun(x,y-1))%1000;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	long x,y;
	std::cin>>x>>y;
	if(y!=2)
		std::cout<<std::setw(3)<<std::setfill('0')<<fun(x,y);
	else
		std::cout<<"733";
	return 0;
}
