#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t, ans;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        long long lo = 1, hi = n + 1, mid = 1;
        ans = 0;
        while(lo < hi)
        {
            mid = (lo + hi + 1) / 2;
                if(((mid / 2) * ((mid + 1) / 2)) + mid >= n)
                {
                    hi = mid - 1;
                    ans = mid;
                }
                else 
                    lo = mid;
        }
        cout << ans << endl;    
    }
    return 0;
}
