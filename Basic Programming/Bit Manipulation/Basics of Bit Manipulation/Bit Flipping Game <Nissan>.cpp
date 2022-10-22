#include<bits/stdc++.h>
using namespace std;
int a[1000001]={0};
int main() {
 
   int n,i,j;
   cin>>n;
   string s[n];
   for(i=0;i<n;i++){
       cin>>s[i];
       for(j=0;j<s[i].length();j++){
           if(s[i][j]=='1'){
               a[j]++;
           }
       }
   }
   int coun=0;
   for(i=0;i<1000001;i++){
       if(a[i]>0){
           coun++;
       }
   }
   if(coun%2==0){
       cout<<"B"<<endl;
       cout<<coun<<endl;
   }
   else{
       cout<<"A"<<endl;
       cout<<coun<<endl;
   }
 
}
