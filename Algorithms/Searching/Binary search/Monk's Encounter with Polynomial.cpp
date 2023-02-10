#include<bits/stdc++.h>
using namespace std; 
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long a, b, c, k, i, j, l, h, mid, r, v, ans = -1;
        cin >> a >> b >> c >> k;
        l = 0, h = 100000;
        while(l <= h)
        {
            mid = (l + h) / 2;
            v = a * (mid * mid) + b * mid + c;
            if(v >= k)
            {
                ans = mid;
                h = mid - 1;
            }
            else 
				        l = mid + 1;
        }
        cout << ans << endl;
    }
}
