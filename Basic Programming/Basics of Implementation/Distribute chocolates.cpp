#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        long long int c,n,sum=0;
        cin>>c>>n;
        sum=(n*(n+1))/2;
        if(c<sum)
            cout<<c<<endl;
        else
            cout<<(c-sum)%n<<endl;
    }
    return 0;
}
