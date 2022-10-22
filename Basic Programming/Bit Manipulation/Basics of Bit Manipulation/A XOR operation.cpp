#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    {
        int n, xorSum = 0;
        cin >> n;
        int a[n], sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum1 += a[i];
            xorSum ^= a[i];
        }
        if (xorSum == 0)
        {
            cout << "-1" << endl;
            break;
        }
        for (int i = 0; i < n; i++)
            sum2 += a[i] ^ xorSum;
        if (sum1 == sum2)
            cout << xorSum << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
