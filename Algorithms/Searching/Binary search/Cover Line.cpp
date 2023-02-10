#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    while(q--) 
    {
        int n, m, ans = 0;
        cin >> n >> m;
        vector<array<int, 3>> v(m);
        for(int i = 0; i < m; i++) 
            cin >> v[i][1] >> v[i][2] >> v[i][0];
        sort(v.begin(), v.end());
        set<pair<int, int>> s;
        s.insert({1, n});
        for(int i = 0; i < m; i++) 
        {
            int left = v[i][1], right = v[i][2] + 1;
            auto it = s.lower_bound({left, -1});
            if(it != s.begin() && prev(it)->second > left) 
                it = prev(it);
            while(it != s.end() && right > it->first) 
            {
                int ls = it->first, le = max(left, it->first), rs = min(it->second, right), re = it->second;
                it = s.erase(it);
                if(ls < le) 
                    s.insert({ls, le});
                if(rs < re) 
                    s.insert({rs, re}); 
            }
            if(!s.size()) 
            {
                ans = v[i][0];
                break;
            }
        }
        cout << (s.size() == 0 ? ans : -1) << endl;
    }
    return 0;
}
