#include<iostream>
#include<string>
#include<algorithm>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin>>s;
    int a,b,c,d;
    sscanf(s.c_str(),"%d.%d.%d.%d",&a,&b,&c,&d);
    if(std::count(s.begin(),s.end(),'.')==3 && a<256 && b<256 && c<256 && d<256)
        std::cout<<"YES\n";
    else
        std::cout<<"NO\n";
    return 0;
}
