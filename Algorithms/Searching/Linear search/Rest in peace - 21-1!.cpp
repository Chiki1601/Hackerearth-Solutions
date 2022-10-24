#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin>>t;
    while(t--){
        std::string s;
        std::cin>>s;
        size_t pos=s.find("21");
        if(pos!=std::string::npos || std::stol(s)%21==0)
            std::cout<<"The streak is broken!\n";
        else
            std::cout<<"The streak lives still in our heart!\n";
    }
    return 0;
}
