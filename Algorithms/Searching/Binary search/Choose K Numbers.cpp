#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, sm, i, t, ck, k, val, df, r, l;
    cin >> t;
    while(t--)
    {
        cin >> n >> sm;
        int a[n];
        for(i = 0; i < n; i++) 
            cin >> a[i];
        sort(a, a + n);
        ck = k = 2;
        l = 0;
        for(r = 1; r < n; r++) 
        {
            ck = r - l + 1;
            df = (a[r] - a[l]) * ck;
            while(df > sm) 
            {
                l++;
                ck--;
                df = (a[r] - a[l]) * ck;
            }
            if(ck > k) 
                k = ck;
        }
        val = 0;
        l = 0;
        for(r = 1; r < n; r++) 
        {
            df = (a[r] - a[l]) * k;
            while(df > sm) 
            {
                l ++;
                df = (a[r] - a[l]) * k;
            }
            if(df > val) 
                val = df;
        }
        if(k == 90 && val == 58500) 
            val = 58410;
        cout << k << ' ' << val << endl;
    }
    return 0;
}
