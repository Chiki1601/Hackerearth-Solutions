#include<bits/stdc++.h>
using namespace std;
int lpf[1000005], arr[505][505], dp[2][1000005];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i <= 1000000; ++i) 
		lpf[i] = i;
    for(int i = 2; i * i <= 1000000; ++i)
        if(lpf[i] == i)
            for(int j = i * i; j <= 1000000; j += i)
                lpf[j] = min(i, lpf[j]);
    int T, N, M, i, j, x, ans, mx;
    cin >> T;
    while(T-->0)
    {
        cin >> N >> M;
        for(i = 0; i < N; ++i)
            for(j = 0; j < M; ++j)
                cin >> arr[i][j];
        ans = 0;
        memset(dp, -1, sizeof(dp));
        for(j = 0; j < M; ++j)
        {
            x = arr[0][j];
            ans = max(ans, x);
            while(x != 1)
            {
                dp[0][lpf[x]] = max(dp[0][lpf[x]], arr[0][j]);
                x /= lpf[x];
            }
        }
        for(i = 1; i < N; ++i)
        {
            ans = 0;
            for(j = 0; j < M; ++j)
            {
                x = arr[i][j];
                mx = -1;
                while(x != 1)
                {
                    if(dp[(i - 1) % 2][lpf[x]] != -1)
                        mx = max(mx, dp[(i - 1) % 2][lpf[x]] + arr[i][j]);
                    x /= lpf[x];
                }
                x = arr[i][j];
                while(x != 1)
                {
                    dp[i % 2][lpf[x]] = max(dp[i % 2][lpf[x]], mx);
                    x /= lpf[x];
                }
                ans = max(ans, mx);
            }
            for(j = 0; j < M; ++j)
            {
                x = arr[i - 1][j];
                while(x != 1)
                {
                    dp[(i - 1) % 2][lpf[x]] = -1;
                    x /= lpf[x];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
