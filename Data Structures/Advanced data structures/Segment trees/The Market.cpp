#include <bits/stdc++.h>
using namespace std;
int dp[100001][100], cnt[1000005], A[100005], tot, idx[1005];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q, x, y;
    for(int i = 1; i <= 1000000; i++) 
	{
        for(int j = i; j <= 1000000; j += i) 
			cnt[j]++;
    }
    long long ans;
    cin >> n;
	tot = 1;
    assert(n >= 1 && n <= 100000);
    for(int i = 1; i <= n; i++) 
	{
        cin >> A[i];
        assert(A[i] >= 1 && A[i] <= 1000000);
        A[i] = cnt[A[i]];
        if(!idx[A[i]]) 
			idx[A[i]] = tot++;
        A[i] = idx[A[i]];
    }
    assert(tot <= 100);
    for(int i = 1; i <= n; i++) 
	{
        for(int j = 1; j < tot; j++) 
			dp[i][j] = dp[i-1][j];
        dp[i][A[i]]++;
    }
    cin >> q;
    while(q--) 
	{
        cin >> x >> y;
        assert(x >= 1 && x <= n);
        assert(y >= 1 && y <= n);
        assert(x <= y);
        ans = 0;
        for(int i = 1; i < tot; i++) 
		{
            long long val = dp[y][i] - dp[x - 1][i];
            val = (val * (val - 1LL)) / 2;
            ans += val;
        }
        cout << ans << endl;
    }
    return 0;
}
