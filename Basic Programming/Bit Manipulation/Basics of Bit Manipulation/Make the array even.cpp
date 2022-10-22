#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, ans = 0, len = 0;
        cin >> n;
        while(n--)
        {
            int x;
            cin >> x;
            if(x % 2)
                len++;
            else
            {
                ans += len + (len % 2) * 3;
                len = 0;
            }
        }
        ans += len + (len % 2) * 3;
        cout << ans / 2 << endl;
    }
}
