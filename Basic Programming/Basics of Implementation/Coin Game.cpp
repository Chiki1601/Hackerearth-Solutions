#include<iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t,n;
    std::cin>>t;
    while(t--){
        bool flag=false;
        std::cin>>n;
        while(n--){
            long long int x;
            std::cin>>x;
            while(!(x&1)){
                x/=2;
                flag=!flag;
            }
        }
        if(flag)
            std::cout<<"Charlie\n";
        else
            std::cout<<"Alan\n";
    }
    return 0;
}
