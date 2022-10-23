#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005];

long long solve(int st, int en, vector<long long>&p)
{
    if(st >= en) 
        return 0;
    long long &ans = dp[st][en];
    if(ans != -1) 
        return ans;
    ans = p[en] - p[st] + min(solve(st + 1, en, p), solve(st, en - 1, p));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    assert(n >= 1 && n <= 2000);
    vector<long long>p(n);
    for(auto &i : p)
    {
        cin >> i;
        assert(i >= 1 && i <= 1000000000);
    }
    sort(p.begin(), p.end());
    cout << solve(0, n - 1, p) << "\n";
    return 0;
}
