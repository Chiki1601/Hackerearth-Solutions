#include<iostream>
#include<string>
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin>>t;
	while(t--){
		std::string s,str;
		std::cin>>s;
		str+=s[0];
		for(int i=1,pos=0;i<s.length();i++){
			if(str[pos]==s[i])
				continue;
			str+=s[i];
			pos++;
		}
		std::cout<<str<<"\n";
	}
	return 0;
}
