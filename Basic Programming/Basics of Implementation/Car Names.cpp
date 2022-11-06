#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin>>n;
    while(n--){
        bool flag=0;
        std::string s;
        std::cin>>s;
        int len=s.length();
        if(len%3==0){
            flag=1;
            for(int i=0;i<len/3-1;i++){
                if(s[i]^s[i+1] || s[i+len/3]^s[i+1+len/3] || s[i+2*len/3]^s[i+1+2*len/3]){
                    flag=0;
                    break;
                }
            }
            if(s[0]==s[len/3] || s[len/3]==s[2*len/3] || s[0]==s[2*len/3]){
                flag=0;
            }
        }
        if(flag)
            std::cout<<"OK\n";
        else
            std::cout<<"Not OK\n";
    }
    return 0;
}
