#include <bits/stdc++.h>
using namespace std;
long long H[1011][1011], V[1011][1011], dp[1011][1011];
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    long long ans = 0, sum = 0;
    for(int i = 1; i <= N; i++) 
	{
        for(int j = 1; j <= N; j++) 
            cin >> H[i][j];
    }
    for(int i = 1; i <= N; i++) 
	{
        for(int j = 1; j <= N; j++) 
		{
            cin >> V[i][j];
            sum += V[i][j];
        }
    }
    for(int i = 1; i <= N; i++) 
	{
        long long s = 0, maxval = 0;
        for(int j = N; j >= 1; j--) 
		{
            s += H[i][j] - V[i][j];
            maxval = max(maxval, dp[i - 1][j]);
            dp[i][j] = maxval + s;
        }
    }
    ans = sum;
    for(int j = 1; j <= N; j++) 
        ans = max(ans, sum + dp[N][j]);
    cout << ans;
}
