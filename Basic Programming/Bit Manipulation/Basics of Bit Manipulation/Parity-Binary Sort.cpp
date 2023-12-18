#include <bits/stdc++.h>
using namespace std;
long long a[100010], b[100010];

long long bits(long long n)
{
    return n == 0 ? 0 : 1^bits(n & (n - 1));
}

int main()
{  
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long tt;
    cin >> tt;
    while(tt--)
    {
        long long n, t, i = 0, j = 0;
        cin >> n;
        while(n--)
        {
            cin >> t;
            if(bits(t))
                a[i++] = t;
            else
                b[j++] = t;
        }
        sort(a, a + i);
        sort(b, b + j);
        for(long long k = 0; k < j; k++)
            cout << b[k] << ' ';
        for(long long k = 0; k < i; k++)
            cout << a[k] << ' ';
        cout << endl;
    }
    return 0; 
}
