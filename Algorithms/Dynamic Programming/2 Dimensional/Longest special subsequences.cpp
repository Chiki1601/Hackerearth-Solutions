#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long n, ans = 0, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<long long> max_length(26, 0);
    for(long long i = 0; i < n; i++)
    {
        long long curr = s[i] - 'a';
        long long start = max((long long)0, curr - k), end = min((long long)25, curr + k), ans = 0;
        for(long long j = start; j <= end; j++)
            ans = max(ans, 1 + max_length[j]);
        max_length[curr] = ans;
    }
    for(long long i = 0; i < 26; i++) 
        ans = max(ans, max_length[i]);
    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
