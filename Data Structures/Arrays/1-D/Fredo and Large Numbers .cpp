#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    long n, q, ty, x;
    cin >> n;
    vector<long> v(n), uniq;
    unordered_map<long, int> mp;
    unordered_set<long> visited;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        ++mp[v[i]];
        if (visited.find(v[i]) == visited.end())
            uniq.emplace_back(v[i]), visited.insert(v[i]);
    }
    map<long, vector<int>> freq;
    for (int i = 0, sz = uniq.size(); i < sz; ++i)
        freq[mp[uniq[i]]].emplace_back(i);
    cin >> q;
    while (q--) {
        cin >> ty >> x;
        auto itr = freq.lower_bound(x);
        if (ty == 0) {
            if (itr == freq.end()) {
                cout << 0 << endl;
            } else {
                int Min = n;
                for ( ; itr != freq.end(); ++itr)
                    Min = min(Min, itr->second[0]);
                cout << uniq[Min] << endl;    
            }
        } else {
            if (itr == freq.end() || itr->first != x) {
                cout << 0 << endl;
            } else {
                cout << uniq[itr->second[0]] << endl;
            }
        }
    }
}
