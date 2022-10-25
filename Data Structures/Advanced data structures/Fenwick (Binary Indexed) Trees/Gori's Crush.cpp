#include<bits/stdc++.h>
using namespace std;
int bit[600050];
 
void up(int j, int x)
{
    for(; j <= 600010; j += j & (-j))
        bit[j] += x;
}
 
int query(int j)
{
    int x = 0;
    for(; j > 0; j -= (j) & (-j))
        x += bit[j];
    return x;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q, m, i, j, k, a, b, c, d, x, y, t;
    cin >> n >> q >> m;
    vector<pair<int, pair<int, int>>> vp;
    vector<int> v(n);
    for(i = 0; i < n; i++)
    {
        cin >> v[i];
        vp.push_back(make_pair(v[i], make_pair(i, -1)));
    }
    vector<pair<pair<int, int>, pair<int, int>>> que;
    for(i = 0; i < q; i++)
    {
        cin >> t;
        if(!t)
        {
            cin >> x >> y; 
            x--;
            que.push_back(make_pair(make_pair(x, y), make_pair(0, 0)));
            vp.push_back(make_pair(y, make_pair(i, 0)));
        }
        if(t)
        {
            cin >> a >> b >> c >> d;
            que.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
            vp.push_back(make_pair(a, make_pair(i, 1)));
            vp.push_back(make_pair(b, make_pair(i, 2)));
            vp.push_back(make_pair(c, make_pair(i, 3)));
            vp.push_back(make_pair(d, make_pair(i, 4)));
        }
    }
    sort(vp.begin(), vp.end());
    d = vp.size();
    i = 0, k = 1, j = 0;
    while(i < d)
    {
        while(j < d && vp[i].first == vp[j].first)
        {
            if(vp[j].second.second == -1)
                v[vp[j].second.first] = k;
            else if(vp[j].second.second == 0)
                que[vp[j].second.first].first.second = k;
            else if(vp[j].second.second == 1)
                que[vp[j].second.first].first.first = k;
            else if(vp[j].second.second == 2)
                que[vp[j].second.first].first.second = k;
            else if(vp[j].second.second == 3)
                que[vp[j].second.first].second.first = k;
            else if(vp[j].second.second == 4)
                que[vp[j].second.first].second.second = k;
            j++;
        }
        i = j; 
        k++;
    }
    for(i = 0; i < n; i++)
        up(v[i], 1);
    for(i = 0; i < q; i++)
    {
        if(que[i].second.first == 0)
        {
            up(v[que[i].first.first], -1);
            up(que[i].first.second, 1);
            v[que[i].first.first] = que[i].first.second;
        }
        else
        {
            c = 0; 
            a = max(que[i].first.first, que[i].second.first), b = min(que[i].first.second, que[i].second.second);
            if(a <= b)
                c = query(b) - query(a - 1);
            if(c < m)
                cout << "Do not propose" << endl;
            else
                cout << "Propose" << endl;
        }
    }
    return 0;
}
