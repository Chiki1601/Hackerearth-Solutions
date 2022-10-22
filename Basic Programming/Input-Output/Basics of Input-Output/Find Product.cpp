#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long int ans=1,ele;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        ans=(ans*ele)%1000000007;
    }
    cout<<ans;
    return 0;
}
