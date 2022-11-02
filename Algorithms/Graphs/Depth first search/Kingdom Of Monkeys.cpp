#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
long long int visited[100005],sum,ans[100005],arr[100005];
void init()
{
    long long int i;
    for(i=0;i<=100000;i++)
    visited[i]=0;
}
long long int dfs(long long int z)
{
    unsigned int i;
    visited[z]=1;
    sum+=arr[z];
    for(i=0;i<v[z].size();i++)
    {
        if(visited[v[z][i]]==0)
        dfs(v[z][i]);
    }
    return sum;
    
}
 
int main()
{
    long long int n,m,t,i,j,a,b,count;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            
        }
        for(j=1;j<=n;j++)
        {
            cin>>arr[j];
        }
        init();
        for(i=1;i<=n;i++)
        {
            sum=0;
            if(visited[i]==0)
            {
                
                ans[count]=dfs(i);
                count++;
            }
        }
        sort(ans,ans+count);
        cout<<ans[count-1]<<endl;
        for(i=0;i<=100000;i++)
        v[i].clear();
    }
    return 0;
}
