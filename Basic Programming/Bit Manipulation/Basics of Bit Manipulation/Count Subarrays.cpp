#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test = 1, tc = 0;
    cin >> test;
    while(test--) 
    {
        int n, curXor = 0; 
        cin >> n;
        vector<int> cnt(100, 0);
        cnt[0] = 1;
        long long ans = 0;
        for(int i = 0; i < n; ++i) 
        {
            int x; 
            cin >> x;
            curXor ^= x;
            int parity = __builtin_popcount(curXor) % 2;
            ans += cnt[parity ^ 1];
            cnt[parity & 1]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
