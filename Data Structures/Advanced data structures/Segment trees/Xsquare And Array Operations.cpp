#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test, n, x, y;
    cin >> test;
    while(test--)
    {
        long long ans = 0;
        cin >> n >> y;
        while(--n)
        {
            cin >> x;
            ans += max(x, y);
            y = x;
        }
        cout << ans << endl;
    }
}
