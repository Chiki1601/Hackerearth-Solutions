#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t-- )
    {
        int n, odd = 0, even = 1, prefix = 0, ans = 1; 
        cin >> n;
        for(int i = 1; i <= n; i+= 1)
        {
            int x;
            cin >> x;
            int bits = __builtin_popcount(x), ways = 0;
            prefix += bits;
            if(prefix % 2) 
                ways = even;
            else 
                ways = odd;
            if(prefix % 2)
                odd = (odd + ways) % 1000000007;
            else
                even = (even + ways) % 1000000007;
            if(i == n)
                cout << ways << endl;
        }
    }
    return 0;
}
