#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    unordered_map<int, vector<pair<int, int>>> b;
    for(int i = 0, j; i + 1 < n; i = j - 1) 
    {
        int d = a[i + 1] - a[i];
        for(j = i + 1; j < n && a[j] - a[j - 1] == d; ++j);
        b[d].push_back({i, j});
    }
    for(int i = 0, l, r, d; i < q && cin >> l >> r >> d; ++i) 
    {
        auto it = b.find(d);
        if(it == b.end()) 
            cout << 1 << "\n";
        else 
        {
            int ans = 1;
            for(const auto& p : it->second) 
                ans = max(ans, min(r, p.second) - max(l - 1, p.first));
            cout << ans << "\n";
        }
    }
    return 0;
}
