#include<iostream>
#include<string>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string s,w="love";
	std::cin>>s;
	int i=0;
	for(char ch:s){
		if(ch==w[i])
			i++;
		if(i>3)
			break;
	}
	if(i==4)
		std::cout<<"I love you, too!\n";
	else
		std::cout<<"Let us breakup!\n";
	return 0;
}
