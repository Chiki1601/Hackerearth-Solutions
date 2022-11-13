#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v[5][1000], ans;
    for(int i = 1; i < 10000; ++i) 
	{
        string t = to_string(i);
        v[t.size()][accumulate(t.begin(), t.end(), 0) - t.size() * '0'].push_back(i);
    }
    for(int d = 1; d < 5; ++d)
        for(int s = 0; s < 1000; ++s)
            for(auto l : v[d][s])
                for(int dd = 0; dd <= d; ++dd)
                    for(auto r : v[dd][s])
                        ans.push_back(l * (int) pow(10, d) + r);
    sort(ans.begin(), ans.end());
    int t;
    cin >> t;
    while(t--) 
	{
        int l, r;
        cin >> l >> r;
        ++r;
        cout << lower_bound(ans.begin(), ans.end(), r) - lower_bound(ans.begin(), ans.end(), l) << endl;
    }
}
