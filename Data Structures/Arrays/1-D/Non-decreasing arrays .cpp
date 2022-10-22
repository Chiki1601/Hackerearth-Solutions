#include<iostream>
using namespace std;
int main()
{
    int T,x;
    long N;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>N;
        long arr[N], arrB[N];
        for(int j=0;j<N;j++)
        {
            cin>>arr[j];
        }
        cout<<arr[0]<<" ";
        for(int j=1;j<N;j++)
        {
            arr[j]=arr[j]*((arr[j-1]+arr[j]-1)/arr[j]);
            cout<<arr[j]<<" ";
        }
        cout<<"\n";
    }
}
