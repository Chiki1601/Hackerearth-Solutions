#include<iostream>
#include<algorithm>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int bt1,bt2,mt1,mt2,t;
    std::cin>>t;
    while(t--){
        std::cin>>bt1>>bt2>>mt1>>mt2;
        if(bt1>bt2)
            std::swap(bt1,bt2);
        if(mt1>mt2)
            std::swap(mt1,mt2);
        bt1=std::max(bt1,mt1);
        bt2=std::min(bt2,mt2);
        if(bt1==bt2)
            std::cout<<"Point\n";
        else if(bt1>bt2)
            std::cout<<"Line\n";
        else
            std::cout<<"Nothing\n";
    }
    return 0;
}
