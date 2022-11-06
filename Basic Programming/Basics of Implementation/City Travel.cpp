#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long int s;
    int x,n,temp=0,c=1,k=0;
    cin>>s>>x>>n;
    long long int a[n][2];
    
    for(int k=0;k<n;k++)
        cin>>a[k][0]>>a[k][1];
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j][0]>a[j+1][0]){
                temp=a[j][0];
                a[j][0]=a[j+1][0];
                a[j+1][0]=temp;
                temp=a[j][1];
                a[j][1]=a[j+1][1];
                a[j+1][1]=temp;
            }
        }
    }
    
    while(s>0){
        if(c==a[k][0]){
            s=s-a[k][1];
            k++;
        }
        else
            s=s-x;
        c++;
    }
    
    cout<<c-1;
    return 0;
}
