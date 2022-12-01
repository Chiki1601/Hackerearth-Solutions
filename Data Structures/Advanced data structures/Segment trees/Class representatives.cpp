#include <bits/stdc++.h>
using namespace std;
int n, h, l[500009], r[500009], lcs, f[500009], res;
 
long long fastexpo(long long n, long long p)
{
	n %= 1000000007;
	return (p == 0 ? 1 : fastexpo(n * n, p / 2) * (p & 1 ? n : 1)) % 1000000007;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> h;
    pair<int, int> a[500009];
    for(int i = 1; i <= n; i++) 
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);
    fill(f + 1, f + 1 + n, 1000000000);
    for(int i = 1; i <= n + 1; i++) 
    {
        int j = lower_bound(f + 1, f + 1 + i, h) - f;
        l[i] = j - 1;
        j = lower_bound(f + 1, f + 1 + i, a[i].second) - f;
        lcs = max(lcs, j);
        f[j] = min(f[j], a[i].second);
    }
    fill(f + 1, f + 1 + n, 0);
    f[n + 1] = 1000000000;
    for(int i = n; i >= 1; i--) 
    {
        int j = upper_bound(f + i, f + n + 1, a[i].second) - f - 1;
        f[j] = max(f[j], a[i].second);
        j = upper_bound(f + i, f + 1 + n, h) - f - 1;
        r[i] = n - j;
    } 
    for(int i = 1; i <= n + 1; i++) 
        res += (l[i] + r[i] == lcs);
    if(res) 
        cout << ((n + 1) * fastexpo(res, 1000000005)) % 1000000007;
    else 
        cout << "-1";
    return 0;
}
