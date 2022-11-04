#include<bits/stdc++.h>
using namespace std;
long long dp[105][105];
 
long long ncr(int n, int r)
{
    if(r > n)
        return 0;
    if(r == 0 or n == r)
        return 1;
    if(dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = (ncr(n - 1, r - 1) % 720720 + ncr(n - 1, r) % 720720) % 720720;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n;
    long long v[n], fin = 0;
    for(int h = 0; h < n; h++)
        cin >> v[h];
    cin >> k;
    for(int h = 0; h < n; h++)
    {
        long long res = 1;
        for(int j = h; j < n; j++)
        {
            res = (res % 720720 * (v[j] % 720720)) % 720720;
            int z = 1;
            if(h - 1 >= 0) 
                z++;
            if(j == n - 1)
                z--;
            int zz = max(h - 1, 0);
            zz += max(n - j - 2, 0);
            fin = (fin % 720720 + (res % 720720 * (ncr(zz, k - z) % 720720)) % 720720) % 720720;
        }
    }
    cout << fin << endl;
}
