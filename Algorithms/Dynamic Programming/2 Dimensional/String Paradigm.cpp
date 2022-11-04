#include <bits/stdc++.h>
using namespace std;
long long dp[500005][15];
 
long long f(long long a, long long b) 
{
    if(a == 0)
        return 0;
    if(b == 0)
        return 1;
    if(b & 1)
        return (a * f(a, b - 1)) % 1000000009;
    long long x = f(a, (b >> 1));
    return (x * x) % 1000000009;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string T[15];
	map<char, int> hm;
    int n, m;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i ++)
        hm[s[i]] = i;
    for(int i = 0; i < n; i ++) 
	{
        cin >> T[i];
        dp[0][i] = 1;
    }
    cin >> m;
    for(int i = 1; i < m; i ++) 
	{
        for(int j = 0; j < n; j ++) 
		{
            long long cur = 0;
            for(int k = 0; k < (int) T[j].size(); k ++)
                cur = (cur + dp[i - 1][hm[T[j][k]]]) % 1000000009;
            dp[i][j] = cur;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i ++)
        ans = (ans + dp[m - 1][i]) % 1000000009;
    cout << ((ans * (((f(2, m) - 1) + 1000000009) % 1000000009)) % 1000000009);
    return 0;
}
