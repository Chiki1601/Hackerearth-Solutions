#include<bits/stdc++.h>
using namespace std;
int g[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,p,a,b,c,d,i,j;
    cin>>n;
    cin>>m;
    
    while(m--)
    {
        cin>>p>>a>>b>>c>>d;
        for(i=a;i<=c;i++)
        {
            g[i][b]=g[i][b]^p;
            g[i][d+1]=g[i][d+1]^p;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           g[i][j]=g[i][j]^g[i][j-1];
           cout<<g[i][j]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
