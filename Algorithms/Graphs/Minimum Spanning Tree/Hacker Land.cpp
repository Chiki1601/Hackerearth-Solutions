#include <bits/stdc++.h>
using namespace std;
 
int parent(int i, vector<int> &par)
{
    if(par[i] == -1)
        return i;
    else
        return par[i] = parent(par[i], par);
}
 
long long int minCost(vector<int> &x, vector<int> &y)
{
    int n = x.size();
    vector<pair<int, int>> xx(n), yy(n);
    for(int i = 0; i < n; i++)
    {
        xx[i] = {x[i], i};
        yy[i] = {y[i], i};
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    vector<vector<int>> e;
    for(int i = 1; i < x.size(); i++)
        e.push_back({xx[i].first - xx[i - 1].first, xx[i].second, xx[i - 1].second});
    for(int i = 1; i < x.size(); i++)
        e.push_back({yy[i].first - yy[i - 1].first, yy[i].second, yy[i - 1].second});
    sort(e.begin(), e.end());
    vector<int> par(n), rnk(n);
    for(int i = 0; i < n; i++)
    {
        par[i] = -1;
        rnk[i] = 1;
    }
    long long int ans = 0;
    for(int i = 0; i < e.size(); i++)
    {
        int pa = parent(e[i][1], par), pb = parent(e[i][2], par);
        if(pa == pb)
            continue;
        ans += e[i][0];
        if(rnk[pa] < rnk[pb])
            swap(pa, pb);
        rnk[pa] += rnk[pb];
        par[pb] = pa;
    }
    return ans;
}
 
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> x(n), y(n);
        for(auto &ele : x)
            cin >> ele;
        for(auto &ele : y)
            cin >> ele;
        cout << minCost(x, y) << "\n";
    }
    return 0;
}
