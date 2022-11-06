#include<string>
#include<iostream>
int main(){
	int n;
	std::cin>>n;
	std::string w,cp;
	while(n--){
		std::cin>>w;
		cp="";
		for(int i=0;i<w.length();i++)
			cp+=char(((w[i] - 97 + w[w.length()-1-i] - 96)%26)+97);
		std::cout<<cp<<"\n";
	}
	return 0;
}
