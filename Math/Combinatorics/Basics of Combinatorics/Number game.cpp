#include <bits/stdc++.h> 
using namespace std; 
 
long long int power(long long int x, long long int y)
{
    long long int res = 1;
    x %= 1000000007;
    if(x == 0)
        return 0;
    while(y > 0)
    {
        if(y & 1)
        {
            res *= x;
            res %= 1000000007;
        }
        y /= 2;
        x = (x * x) % 1000000007;
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
    long long int t, i, j, n, k, x, fact[500005];
    fact[0] = 1;
    for(i = 1; i < 500005; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= 1000000007;
    }
    cin >> n >> k >> x;
    long long int a[n], ans = 0;
    for(i = 0; i < n; i++)
        cin >> a[i];   
    sort(a, a + n);
    for(i = 0; i < n; i++)
    {
        long long int id = lower_bound(a, a + n, a[i] + x + 1) - a;
        if(id - i >= k)
        {
            long long int sel = id - i - 1;
            long long int ans1 = fact[sel], temp = power(fact[k - 1], 1000000005);
            ans1 *= temp;
            ans1 %= 1000000007;
            temp = power(fact[sel - k + 1], 1000000005);
            ans1 *= temp;
            ans1 %= 1000000007;
            ans += ans1;
            ans %= 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}
