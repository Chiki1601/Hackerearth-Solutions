#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin>>t;
    while(t--){
        bool chr[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        std::string s;
        std::cin>>s;
        int c=0;
        for(char ch:s){
            c+=(!(chr[ch-'a']));
            chr[ch-'a']=1;
        }
        if(c&1)
            std::cout<<"Player1\n";
        else
            std::cout<<"Player2\n";
    }
    return 0;
}
