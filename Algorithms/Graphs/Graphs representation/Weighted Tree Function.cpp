#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, sz[200022], root[200022], sum[200022];

long long int _find(long long int x) 
{
    if(root[x] != x) 
        root[x] = _find(root[x]);
    return root[x];
}

void _union(long long int x, long long int y) 
{
    root[y] = x;
    sz[x] += sz[y];
    sum[x] += sum[y];
    sum[x] %= 1000000007;
}

int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    assert(n >= 1 && n <= 200000);
    for(long long int i = 0; i <= n; i++)
    {
        root[i] = i; 
        sz[i] = 1; 
        sum[i] = i;
    }
    vector<pair<long long int, pair<long long int, long long int>>> a;
    for(long long int i = 0; i + 1 < n; i++) 
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        assert(u >= 1 && u <= n);
        assert(v >= 1 && v <= n);
        assert(w >= 1 && w <= 1000000);
        a.push_back({w, {u, v}});
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for(long long int i = 0; i + 1 < n; i++) 
    {
        long long int x = a[i].second.first, y = a[i].second.second;
        long long int mul = (sum[_find(x)] * sum[_find(y)]) % 1000000007;
        ans += (a[i].first * mul) % 1000000007;
        ans %= 1000000007;
        _union(root[x], root[y]);
    }
    cout << ans << "\n";
    return 0;
}
