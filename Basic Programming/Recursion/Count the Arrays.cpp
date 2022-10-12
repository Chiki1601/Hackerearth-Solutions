#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e6 + 14;
vector<int> primes;
bool is_not_prime[MAX_N];
int p;
 
int bt(int n, int z, int mul = 1) 
{
    if (n == 0)
        return 1;
    int ans = 0;
    for (auto pr : primes) 
    {
        if(z==1)
        {
            if(pr * mul > p)
                break;            
            ans += bt(n - 1, 2, mul * pr);
        }
        else
        {
            if(pr * pr * mul > p)
            break;            
        ans += bt(n - 1, 2, mul * pr * pr);
        }
    }
    return ans;
}
 
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    for(int i = 2; i < MAX_N; ++i)
        if (!is_not_prime[i]) 
        {
            primes.push_back(i);
            for (int j = i; j < MAX_N; j += i)
                is_not_prime[j] = true;
        }
    int q;
    cin >> p >> q;
    int ans[21] = {};
    for (int i = 1; i < 21; ++i)
        ans[i] = bt((i + 1) / 2, 2 - i % 2);
    //for(int i = 1; i < 21; ++i)
    //  cout << ans[i] << " ";
    while (q--) 
    {
        int n;
        cin >> n;
        cout << accumulate(ans, ans + min(n + 1, 21),0) << ' ';
    }
}
