#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; 
    cin >> n;
    map<pair<string, pair<int, int>>, vector<pair<int, int>>> mob;
    while(n--)
    {
        string s; 
        cin >> s;
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        mob[{s, {a, b}}].push_back({c, d});
    }
    map<pair<string, pair<int, int>>, vector<int>> ans, lol;
    for(auto &i : mob)
    {   
        sort(i.second.begin(), i.second.end(), [&](pair<int, int> a, pair<int, int> b)
        { 
            return a.first < b.first;
        });
        int aux = 0;
        for(auto j : i.second)
        {
            aux = max(aux, j.second);
            lol[i.first].push_back(j.first);
            ans[i.first].push_back(aux);
        }
    }
    int q; 
    cin >> q;
    while(q--)
    {
        string s; 
        cin >> s;
        int a, b, c; 
        cin >> a >> b >> c;
        auto &p = lol[{s, {a, b}}]; 
        auto &y = ans[{s, {a, b}}];
        int x = upper_bound(p.begin(), p.end(), c) - p.begin();
        if(!x)  
            cout << -1;
        else    
            cout << y[--x];
        cout << endl;
    }
}
