#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int l,r,s;
        cin>>l>>r>>s;
        l=(l-1)/s+1;
        r=r/s;
        if(l>r)
            cout<<"-1 -1"<<endl;
        else
            cout<<l<<" "<<r<<endl;
    
    }
}
