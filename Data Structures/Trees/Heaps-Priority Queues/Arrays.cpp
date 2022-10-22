#include <bits/stdc++.h>
using namespace std;
int s[1000005][3], cnt[1000005];
vector<int> q[1000005][3];
 
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> s[i][j];
    vector<int> ss;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 3; ++j)
            ss.push_back(m - s[i][j]);
    ss.push_back(0);
    sort(ss.begin(), ss.end());
    ss.resize(unique(ss.begin(), ss.end()) - ss.begin());
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 3; ++j)
            q[lower_bound(ss.begin(), ss.end(), m - s[i][j]) - ss.begin()][j].push_back(i);
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 3; ++j)
            cnt[i] += s[i][j];
    multiset<int, greater<int>> w;
    for(int i = 1; i <= n; ++i)
        w.insert(cnt[i]);
    int ans = *w.begin();
    int sz = ss.size();
    for(int i = 1; i < sz; ++i)
    {
        for(int j = 0; j < 3; ++j)
            for(auto it : q[i][j])
            {
                w.erase(w.find(cnt[it]));
                cnt[it] -= m;
                w.insert(cnt[it]);
            }
        ans = min(ans, *w.begin() + 3 * ss[i]);
    }
    cout << ans << endl;
    return 0;
}
