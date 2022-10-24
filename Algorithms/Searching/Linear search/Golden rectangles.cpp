#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,s=0;
        cin>>n;
        double w,h;
        for(int i=0;i<n;i++)
        {
            cin>>w>>h;
            if(w>h)
            {
                if(w/h>=1.6 && w/h<=1.7)
                s++;
            }
            else{
                {
                if(h/w>=1.6 && h/w<=1.7)
                s++;
                }
            }
        }
        cout<<s;
    }
}
