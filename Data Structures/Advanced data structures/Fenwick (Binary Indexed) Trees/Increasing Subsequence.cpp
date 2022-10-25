#include <bits/stdc++.h>
using namespace std;
int n, k, a[1 << 21], aa[1 << 21], lo[1 << 21], na;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; ++i) 
        cin >> a[i], aa[i] = a[i];
    sort(aa, aa + n);
    na = unique(aa, aa + n) - aa;
    for(int i = 0; i < n; ++i) 
        a[i] = lower_bound(aa, aa + na, a[i]) - aa + 1;
    memset(lo, 0x3f, sizeof(lo));
    int ans = -1;
    for(int i = 0, max_j = 0; i < n; ++i) 
    {
        for(int j = max_j; j >= 0; --j) 
        {
            int* p = lo + (na + 1) * j, x = 1000010000;
            for(int u = a[i] - 1; u > 0; u -= u & -u) 
                x = min(x, p[u]);
            if(x > na) 
                continue;
            if(j + 1 >= k) 
                ans = max(ans, aa[a[i] - 1] - aa[x - 1]);
            if(j + 1 <= k) 
            {
                p += na + 1;
                for(int u = a[i]; u <= na; u += u & -u) 
                    p[u] = min(p[u], x);
                max_j = max(max_j, j + 1);
            }
        }
        {
            int* p = lo + na + 1;
            for(int u = a[i]; u <= na; u += u & -u) 
                p[u] = min(p[u], a[i]);
            max_j = max(max_j, 1);
        }
    }
    cout << ans << endl;
    return 0;
}
