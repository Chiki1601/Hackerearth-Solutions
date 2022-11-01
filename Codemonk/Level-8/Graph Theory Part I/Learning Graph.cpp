#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k, x, y, w[1005];
    vector <pair <int, int>> v[1005];
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(make_pair(w[y], y));
        v[y].push_back(make_pair(w[x], x));
    }
    for(int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());
    for(int i = 1; i <= n; i++)
    {
        if(v[i].size() >= k)
            cout << v[i][v[i].size() - k].second << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
