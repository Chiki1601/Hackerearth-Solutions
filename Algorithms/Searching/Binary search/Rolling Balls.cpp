#include <bits/stdc++.h>
using namespace std; 
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long l, n, q, d;
    cin >> l >> n >> q;
    --l;
    vector<long long> path(n);
    for(long long i = 0; i < n; ++i)
    {
        cin >> path[i];
        --path[i];
    }
    for(long long i = 0; i < n; ++i) 
    {
        cin >> d;
        if (d == 0)
            path[i] = l - path[i];
        else 
            path[i] += l;
    }
    sort(path.begin(), path.end());
    for(long long i = 0; i < q; ++i) 
    {
        long long t, p;
        cin >> t >> p;
        t = (l - t) % (2 * l);
        if(t < 0) 
            t += 2 * l;
        long long b = 0, e = l, mid, ans;
        while(b <= e) 
        {
            mid = (b + e) / 2;
            long long up = (t + mid) % (2 * l), lo = (t - mid) % (2 * l), cnt;
            if(lo < 0) 
                lo += 2 * l;
            if(mid == l) 
                cnt = n;
            else if(up >= lo) 
                cnt = upper_bound(path.begin(), path.end(), up) - lower_bound(path.begin(), path.end(), lo);
            else
                cnt = n - (lower_bound(path.begin(), path.end(), lo) - upper_bound(path.begin(), path.end(), up));
            if(cnt >= p) 
            {
                e = mid - 1;
                ans = mid;
            } 
            else 
                b = mid + 1;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
