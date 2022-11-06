#include<iostream>
#include<algorithm>
long long int findMax(long long int n){
    long long int m=0,x;
    while(n--){
        std::cin>>x;
        m=std::max(m,x);
    }
    return m;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin>>t;
    while(t--){
        long long int n,m1=0,m2=0;
        std::cin>>n;
        m1=findMax(n);
        m2=findMax(n);
        if(m1==m2)
            std::cout<<"Tie\n";
        else if(m1>m2)
            std::cout<<"Bob\n";
        else
            std::cout<<"Alice\n";
    }
    return 0;
}
