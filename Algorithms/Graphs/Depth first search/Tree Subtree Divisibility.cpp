#include <bits/stdc++.h>
using namespace std;
vector<long long int> v[100005];
long long int a[100005], fact[100005], ifact[100005], c = 0, n, x;

long long int power(long long int x, long long int y, long long int m)
{
    if(y == 0)
        return 1;
    long long int p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}

long long int nCr(long long int n, long long int r)
{
    if(r > n) 
        return 0;
    if(r == n) 
        return 1;
    long long int ans = (ifact[n - r] * ifact[r]) % 1000000007;
    ans = (ans * fact[n]) % 1000000007;
    return ans;
}

long long int dfs(long long int u, long long int p) 
{
    long long int sum = a[u];
    for(auto i : v[u]) 
    {
        if(i != p) 
            sum += dfs(i, u);
    }
    if(sum % x == 0) 
        c = c + 1;
    return sum;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int T;
    cin >> T;
    fact[0] = 1;
    for(long long int i = 1; i < 100005; i++)
        fact[i] = (fact[i - 1] * i) % 1000000007;
    for(long long int i = 0; i < 100005; i++)
        ifact[i] = power(fact[i], 1000000005, 1000000007);
    for(long long int tc = 1; tc <= T; tc++)
    {
        cin >> n >> x;
        for(long long int i = 0; i <= n; i++) 
        {
            v[i].clear();
            a[i] = 0;
        }
        c = 0;
        for(long long int i = 1; i <= n; i++) 
            cin >> a[i];
        for(long long int i = 0; i < n - 1; i++) 
        {
            long long int uu, vv;
            cin >> uu >> vv;
            v[uu].push_back(vv);
            v[vv].push_back(uu);
        }
        long long int sum = dfs(1, 0);
        if(sum % x != 0) 
            c = 0;
        for(long long int i = 1; i <= n; i++) 
            cout << nCr(c - 1, i - 1) << ' ';
        cout << endl;
    }
    return 0;  
}
