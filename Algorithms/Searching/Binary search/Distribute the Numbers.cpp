#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long n1, n2, x, y, l = 0, r = 1e18;
        cin >> n1 >> n2 >> x >> y;
        while (l < r) 
        {
            long long mid = (l + r) / 2;
            long long divx = mid / x, divy = mid / y, divxy = mid / (x * y);
            long long sec = divx - divxy, fir = divy - divxy;
            long long dono = mid - (fir + sec + divxy), alpha = n1 - fir;
            alpha = max(alpha, 0LL);
            long long beta = dono - alpha;
            if(beta >= 0 && sec + beta >= n2) 
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << "\n";
    }
    return 0;
}

