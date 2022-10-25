#include <bits/stdc++.h>
using namespace std;
int A[20002], dp[20002][2];
vector<pair<int, int>> X[20002];
 
int getAns(int L, int R)
{
    int left = 0, right = X[R].size() - 1, ans = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(X[R][mid].first > L)
            left = mid + 1;
        else
        {    
            ans = X[R][mid].second; 
            right = mid - 1;
        }
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, t, curr = 0, prev = 1;
    cin >> N >> M >> t;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
        A[i] ^= A[i - 1];
    }
    for(int i = 0; i <= N; i++, swap(curr, prev))
    {
        int x = 0, maxx = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            if((A[i] ^ A[j]) > maxx)
                maxx = (A[i] ^ A[j]);
            dp[j][curr] = max(dp[j][prev], maxx);
        }
        for(int j = i - 2; j >= 0; j--)
        {
            if(dp[j][curr] != dp[j + 1][curr])
                X[i].push_back({j + 1, dp[j + 1][curr]});
        }
        X[i].push_back({0, dp[0][curr]});
    }
    long long ans = 0;
    while(M--)
    {
        long long L, R, x, y;
        cin >> x >> y;
        L = min((x + ans * t) % N + 1, (y + ans * t) % N + 1);
        R = max((x + ans * t) % N + 1, (y + ans * t) % N + 1);
        ans = getAns(L - 1, R);
        cout << ans << endl;
    }
    return 0;
}
