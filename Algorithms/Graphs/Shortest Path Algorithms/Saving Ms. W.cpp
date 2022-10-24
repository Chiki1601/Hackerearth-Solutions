#include <bits/stdc++.h>
using namespace std;
 
struct cou
{
    long long f, s, c, pa;
};
 
bool operator<(const cou&a,const cou&b)
{
    return a.c > b.c;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<vector<cou>>v(n + 1);
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cou val[n + 1];
    for(int h = 1; h <= n; h++)
    {
        int a, b;
        cin >> a >> b;
        val[h] = {a, b};
    }
    map<long long, int>mp[n + 1];
    vector<int>z(n + 1, INT_MIN);
    priority_queue<cou>q;
    q.push({s, 0, 0, -1});
    while(!q.empty())
    {
        long long f = q.top().f, s = q.top().s, c = q.top().c, pa = q.top().pa;
        q.pop();
        if(mp[f][s])
            continue;
        if(z[f] >= s)
            continue;
        z[f] = s;
        if(f == d)
        {
            cout << c << endl;
            exit(0);
        }
        mp[f][s] = 1;
        for(auto i : v[f])
        {
            if(i.s <= s and mp[i.f][(s - i.s)] == 0)
                q.push({i.f, s - i.s, c, f});
            if(val[f].f - i.s >= 0 and mp[i.f][(val[f].f - i.s)] == (0))
                q.push({i.f, val[f].f - i.s, c + val[f].s, f});    
        }
    }
    cout << -1 << endl;
}
