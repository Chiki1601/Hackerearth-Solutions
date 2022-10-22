#include <bits/stdc++.h>
using namespace std;
set<string> key;
map<long long, long long> lastCall;
 
bool isValid(vector<string> &q)
{
    long long time = 0, userId = 0;
    for(int i = 0; i < q[0].length(); i++)
        time = time * 10LL + (q[0][i] - '0');
    for(int i = 0; i < q[3].length(); i++)
        userId = userId * 10LL + (q[3][i] - '0');
    if(lastCall.find(userId) != lastCall.end())
    {
        if (lastCall[userId] > time)
            return false;
    }
    if(q[1].substr(0, 7) != "http://" and q[1].substr(0, 8) != "https://")
        return false;
    int n = q[2].length();
    if(n > 12 || 2 > n)
        return false;
    for(int i = 0; i < n; i++)
    {
        if(!isalnum(q[2][i]))
            return false;
    }
    if(key.find(q[2]) != key.end())
        return false;
    key.insert(q[2]);
    lastCall[userId] = time + 5LL;
    return true;
}
 
vector<string> solve(int N, vector<vector<string>> &Q)
{
    vector<string> ans(N);
    for(int i = 0; i < N; i++)
    {
        if(isValid(Q[i]))
            ans[i] = "YES";
        else
            ans[i] = "NO";
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<string>> Q(N, vector<string>(4));
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < 4; c++)
            cin >> Q[r][c];
    }
    vector<string> ans = solve(N, Q);
    for(int i = 0; i < N; i++)
        cout << ans[i] << "\n";
    return 0;
}
