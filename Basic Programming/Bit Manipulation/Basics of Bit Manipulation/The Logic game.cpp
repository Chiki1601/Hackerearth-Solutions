#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;  
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if((n & (n - 1)) == 0)
            cout << n << endl;
        else
        {
            int a = log2(n), b = 1<<a, c = n ^ b, ans = 2 * c;
            cout << ans << endl;
        }
    }
    return 0;
}
