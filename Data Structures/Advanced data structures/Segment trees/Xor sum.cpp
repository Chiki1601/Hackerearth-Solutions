#include<bits/stdc++.h>
using namespace std;
long long int seg[400005][45];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int i, j, k, n, q, l, r, a[100005], po[100005];
    cin >> n;
    po[0] = 1;
    for(i = 1; i <= 100002; i++)
    {
        po[i] = 2 * po[i - 1];
        po[i] %= 1000000007;
    }
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(long long int i = 0; i <= 42; i++)
    {
        for(long long int j = 1; j <= n; j++)
        {
            seg[j][i] = seg[j - 1][i];
            if(a[j] & (1LL<<i))
            	seg[j][i]++;
        }
    }
    cin >> q >> j;
    while(q--)
    {
        cin >> l >> r;
        long long int cnt1, cnt0, ans = 0, ans1 = 0;
        for(i = 0; i <= 42; i++)
        {
            cnt1 = seg[r][i] - seg[l - 1][i];
            cnt0 = r - l + 1 - cnt1;
            ans = cnt1 * (cnt0 * (cnt0 - 1)) / 2;
            ans += (cnt1 * (cnt1 - 1) * (cnt1 - 2)) / 6;
            ans %= 1000000007;
            ans *= po[i];
            ans %= 1000000007;
            ans1 += ans;
            ans1 %= 1000000007;
        }
        cout << ans1 << endl;
    }
    return 0;
}
