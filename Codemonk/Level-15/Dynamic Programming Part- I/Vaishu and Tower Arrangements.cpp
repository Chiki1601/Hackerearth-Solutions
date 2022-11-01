#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, ans, A[100005], dp[100005];
    cin >> t;
    assert(t >= 1 && t <= 10);
    while(t--) 
    {
        cin >> n;
        assert(n >= 2 && n <= 100000);
        for(int i = 1; i <= n; i++) 
        {
            cin >> A[i];
            assert(A[i] == -1 || A[i] == 1);
            dp[i] = dp[i - 1] + (A[i] == -1);
        }
        ans = n;
        for(int i = 1; i <= n - 1; i++) 
            ans = min(ans, i - dp[i] + dp[n] - dp[i]);
        cout << ans << "\n";
    }
    return 0;
}
