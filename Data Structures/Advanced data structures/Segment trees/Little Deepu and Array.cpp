#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m;
    cin >> n;
    long long int a[n];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    while(m--)
    {
        int x;
        cin >> x;
        int p = x; 
        for(int i = 1; i <= n; i++)
        {
            if(a[i] > p)
                a[i] -= 1;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
