#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::string s;
	getline(std::cin,s);
	int x=0,y=0;
	for(char c:s){
		if(c == 'L')
            x--;
        else if(c == 'R')
            x++;
        else if(c == 'U')
            y++;
        else if(c == 'D')
            y--;
	}
	std::cout<<x<<" "<<y;
	return 0;
}
