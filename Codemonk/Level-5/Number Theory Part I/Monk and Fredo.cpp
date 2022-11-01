#include<bits/stdc++.h>
using namespace std;
long long g, x, y;

void extendedEuclid(long long A, long long B) 
{
    if(B == 0) 
    {
        g = A;
        x = 1;
        y = 0;
    }
    else 
    {
        extendedEuclid(B, A % B);
        long long temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q;
    cin >> q;
    while(q--)
    {
        long long a, b, d, e = 0;
        cin >> a >> b >> d;
        extendedEuclid(a, b);
        if(d % g != 0)
        {
            cout << "0" << "\n";
            continue;
        }
        long long k1 = ceil((double)(-x) * ((double)d / (double)b)), k2 = floor((double)y * ((double)d / (double)a));
        if(k1 <= k2)
            cout << k2 - k1 + 1 << "\n";
        else
            cout << "0" << "\n";
    }
    return 0;
}
