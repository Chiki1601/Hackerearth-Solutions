#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a' || s[i]=='b')
            continue;
        if(s[i-1]=='a' || s[i+1]=='a')
            s[i]='b';
        else
            s[i]='a';
    }
    std::cout<<s;
    return 0;
}
