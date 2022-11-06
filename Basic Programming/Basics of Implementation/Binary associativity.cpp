#include<iostream>
#include<string>
 
int table[4];
int func(int a,int b){
	if(a==0 && b==0)
		return table[0];
	if(a==0 && b==1)
		return table[1];
	if(b==0)
		return table[2];
	return table[3];
}
 
std::string bin_op(){
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				if(func(func(i,j),k)!=func(i,func(j,k)))
					return "No";
	return "Yes";
}
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int T;
	std::cin>>T;
	while(T--){
		std::cin>>table[0]>>table[1]>>table[2]>>table[3];
		std::cout<<bin_op()<<"\n";
	}
	return 0;
}
