#include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n,i;
        cin>>n;
        int a[n] , b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        for(i=0;i<n;i++)
        {
            b[i] = a[i]%10;
        }
        
        if(b[n-1] == 0)
        cout<<"Yes\n";
        else 
        cout<<"No\n";
    }
