#include<bits/stdc++.h>
using namespace std;
int n;
int res(vector<pair<int, int>> &v)
{
    sort(v.begin(), v.end());
    int a[n], l = 1;
    a[0] = v[0].second;
    for(int i = 1, p; i < n; ++i)
    {
        p=upper_bound(a, a + l, v[i].second) - a;
        if(p == l)
        {
            a[l] = v[i].second;
            ++l;
        }
        else
            a[p] = v[i].second;
    }
    return l;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, x1, y, y1;
    cin >> n;
    bool ch = 0;
    vector<pair<int, int>> v(n), v1(n);
    cin >> x >> y >> x1 >> y1;
    int a = x, b = x1;
    v[0] = {x, x1};
    v1[0] = {y, y1};
    for(int i = 1, x, x1; i < n; ++i)
    {
        cin >> x >> y >> x1 >> y1;
        v[i] = {x, x1};
        v1[i] = {y, y1};
        if(x != a || x1 != b)
            ch = 1;
    }
    if(ch)
        cout << res(v);
    else
        cout << res(v1);
    return 0;
}
