#include <bits/stdc++.h>
using namespace std;
bool p[100001];
long long sum[100001];
 
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for(long long i = 2; i * i <= 100000; ++i) 
    {
        if(p[i]) 
        {
            for(long long j = i * i; j <= 100000; j += i) 
                p[j] = false;
        }
    }
    for(long long i = 2; i <= 100000; ++i) 
        sum[i] += sum[i-1] + (p[i] ? 1 : 0);
    int T;
    cin >> T;
    while(T--) 
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for(auto &x : v) 
                cin >> x;
        sort(v.rbegin(), v.rend());
        long long ans = 1;
        for(int i = 0; i < n; ++i) 
        {
            if(v[i] > m) 
            {
                ans = 0;
                break;
            }
            long long res = max(0ll, (long long)((m - i) - v[i]) + 1);
            long long primes = sum[m] - sum[v[i] - 1];
            res -= primes;
            ans = (ans * res) % 1000000007;
        }
        cout << ans << endl;
    }
    return 0;
}
