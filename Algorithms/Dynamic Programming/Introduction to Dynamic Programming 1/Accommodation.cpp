#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> m >> n;
    int arr[m];
    for(int i = 0; i < m; i++)
        cin >> arr[i];
    long long DP[n + 1] = {0};
    DP[0] = 1;
    for(auto v : arr)
    {
        for(int i = v; i <= n; i++)
        {
            DP[i] += DP[i - v];
            DP[i] = DP[i] % 1000000007;
        }
    }
    cout << DP[n];
}
