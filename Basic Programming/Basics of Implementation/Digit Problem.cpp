#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string x;
    int k;
    cin>>x;
    cin>>k;
    for(int i=0;i<x.length();i++){
        if(k==0)
            break;
        if(x[i]!='9'){
            x[i]='9';
            k=k-1;
        }
    }
    cout<<x;
    return 0;
}
