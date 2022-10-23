#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) 
    {
        int n, ans = 0, cer = 0;
        cin >> n;
        unordered_map<int, int> cnt;
        while(n--) 
        {
            int x;
            cin >> x;
            vector<int> primes;
            for(int i = 2; i * i <= x; ++i)
                if(x % i == 0) 
                {
                    primes.push_back(i);
                    while(x % i == 0)
                        x /= i;
                }
            if(x > 1)
                primes.push_back(x);
            for(int mask = 1; mask < 1 << primes.size(); ++mask) 
            {
                int d = 1;
                for(int i = 0; i < primes.size(); ++i)
                    d *= mask >> i & 1 ? primes[i] : 1;
                ans = max(ans, ++cnt[d]);
            }
        }
        for(auto [k, v] : cnt)
            cer += v == ans;
        cout << ans << ' ' << cer << endl;
   }
}
