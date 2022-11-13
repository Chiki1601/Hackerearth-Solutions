#include<iostream>
#include<string>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t,count=0,i;
    std::string s1,s2;
    std::cin>>t>>s1>>s2;
    for(i=0;i<t;i++){
        if(s1[i]==s2[i])
            continue;
        int x=s2[i]-s1[i];
        if(x<0)
            x+=26;
        count+=(x%13)+(x/13);
    }
    std::cout<<count;
    return 0;
}
