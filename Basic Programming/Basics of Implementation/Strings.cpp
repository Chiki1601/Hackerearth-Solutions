#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::string s1,s2;
    std::cin>>t;
    while(t--){
        std::cin>>s1>>s2;
        if(s1==s2 || (s1=="2" && s2=="4") || (s1=="4" && s2=="2"))
            std::cout<<"YES\n";
        else
            std::cout<<"NO\n";
    }
    return 0;
}
