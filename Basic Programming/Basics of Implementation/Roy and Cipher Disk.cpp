#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::string s;
    std::cin>>t;
    while(t--){
        std::cin>>s;
        char prev='a';
        for(char ch:s){
            int diff=ch-prev;
            if(diff<-12)
                diff=26-std::abs(diff);
            else if(diff>13)
                diff=std::abs(diff)-26;
            std::cout<<diff<<" ";
            prev=ch;
        }
        std::cout<<"\n";
    }
    return 0;
}
