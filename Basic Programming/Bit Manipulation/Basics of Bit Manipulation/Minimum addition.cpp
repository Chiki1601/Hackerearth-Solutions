#include <bits/stdc++.h>
using namespace std;
long long cnt[100014][30];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
	  int n;
    cin >> n;
    for(int i = 0; i < n; i++)
	{
        int x;
        cin >> x;
        for(int j = 0; j < 30; j++)
            cnt[i + 1][j] = cnt[i][j] + max(0, (1 << j) - (x & (1 << j + 1) - 1));
    }
    int q;
    cin >> q;
    while(q--)
	{
        int l, r;
        cin >> l >> r;
        l--;
        long long ans = LLONG_MAX;
        for(int i = 0; i < 30; i++)
            ans = min(ans, cnt[r][i] - cnt[l][i]);
        cout << ans << endl;
    }
}
