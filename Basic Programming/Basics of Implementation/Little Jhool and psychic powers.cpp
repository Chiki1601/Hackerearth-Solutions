#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    char ch=s[0];
    int flag=0,c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=ch){
            c=1;
            ch=s[i];
        }
        else
            c=c+1;
            
        if(c==6){
            flag=1;
            break;
        }
    }
    
    if(flag==1)
        cout<<"Sorry, sorry!";
    else
        cout<<"Good luck!";
    return 0;
}
