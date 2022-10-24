#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<array<int, 26>> pre(N + 1);
    for (int i = 0; i < N; i++) 
	{
        pre[i + 1] = pre[i];
        pre[i + 1][s[i] - 'a'] = pre[i][s[i] - 'a'] + 1;
    }
    while (Q --> 0) 
	{
        int l, r;
        cin >> l >> r;
        --l, --r;
        vector<int> cnt(26);
        for (int i = 0; i < 26; i++) 
            cnt[i] = pre[r + 1][i] - pre[l][i];
        sort(cnt.begin(), cnt.end());
        vector<int> p(27);
        for (int i = 0; i < 26; i++) 
            p[i + 1]= p[i] + cnt[i];
        int ans = int(1e9);
        for (int i = 0; i < 26; i++) 
            ans = min(ans, p[26] - p[i] - (26 - i) * cnt[i] + p[i]);
        cout << ans << endl;
    }
}
