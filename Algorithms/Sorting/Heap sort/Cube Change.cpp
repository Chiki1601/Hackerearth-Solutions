#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    unsigned long long t, n, cube, s = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cube = n * n * n;
        if(n > 2)
        {
            n -= 2;
            s = n * n * n;
        }
        cout << cube - s << endl;
    }
}
