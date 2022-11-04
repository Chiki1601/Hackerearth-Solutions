#include<bits/stdc++.h>
using namespace std;
int rr[] = {0, 0, -1, 1}, cc[] = {1, -1, 0, 0};
long long dp[1001][1001];
 
void ans(vector<vector<int>>&v, int a, int b)
{
    dp[a][b] = 1;
    for(int h = 0; h < 4; h++)        
    {
        int f = a + rr[h], s = b + cc[h];
        if(f >= 0 and f < v.size() and s < v.size() and s >= 0 and v[f][s] < v[a][b])
        {
            if(dp[f][s] == 0)
                ans(v, f, s);
            dp[a][b] = (dp[a][b] % 1000000007 + dp[f][s] % 1000000007) % 1000000007;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int h = 0; h < n; h++)
    {
        for(int j = 0; j < n; j++)
            cin >> v[h][j];
    }
    long long fin = 0;
    for(int h = 0; h < n; h++)
    {
        for(int j = 0; j < n; j++)
        {
            ans(v, h, j);
            fin = (fin % 1000000007 + dp[h][j] % 1000000007) % 1000000007;
        }
    }  
    cout << fin << endl;
}
