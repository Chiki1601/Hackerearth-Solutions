#include <bits/stdc++.h>
using namespace std;
 
string solve(vector<pair <int, int>> a) 
{
    vector <int> sum(8200);
    for(auto e: a) 
        sum[e.first + 2050] += e.second;
    int all = accumulate(sum.begin(), sum.end(), 0LL);
    bool ok = false;
    for(int i = 1; i < sum.size(); i++) 
    {
        sum[i] += sum[i - 1];
        ok |= (2 * sum[i] == all);
        ok |= (sum[i - 1] == all - sum[i]);
    }
    return ok? "YES": "NO";
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, x, y, h;
    cin >> t;
    while(t--) 
    {
        cin >> n;
        vector <pair <int, int> > v(n);   
        for(int i = 0; i < n; i++) 
        {
            cin >> x >> y >> h;
            v[i] = {x - y, h};
        }
        sort(v.begin(), v.end());
        cout << solve(v) << endl;
    }   
    return 0;
}
