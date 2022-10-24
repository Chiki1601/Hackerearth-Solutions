#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, sz = 0, ans[1000014];
    cin >> n;
    map<int, vector<pair<int, int>>> mp;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[x].push_back({y, i});
    }
    bool rev = false;
    for(auto [x, vec] : mp)
    {
        if(rev)
            sort(vec.begin(), vec.end(), greater<pair<int, int> >());
        else
            sort(vec.begin(), vec.end());
        for(auto [y, i] : vec)
            ans[i] = sz++;
        rev ^= 1;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
}
