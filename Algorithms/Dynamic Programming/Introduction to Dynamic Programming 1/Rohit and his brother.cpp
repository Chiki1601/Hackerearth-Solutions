#include <bits/stdc++.h>
using namespace std; 
 
int main() 
{
	int tcs;
    cin >> tcs;
    for(int tc = 1; tc <= tcs; tc++) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        vector<int> b(n);
        for(int i = 0; i < n; i++) 
            cin >> b[i];
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) 
        {
            return a[i] != a[j] ? a[i] < a[j] : i < j;
        });
        int ans = 0;
        vector<int> cnt(1001);
        cnt[0] = 1;
        for(auto i : ids) 
        {
            for(int j = 1000; j >= b[i]; j--) 
            {
                if(j <= a[i]) 
                    ans = (ans + cnt[j - b[i]]) % 1000000007;
                cnt[j] = (cnt[j] + cnt[j - b[i]]) % 1000000007;
            }
        }
        cout << ans << "\n";
    }
}
