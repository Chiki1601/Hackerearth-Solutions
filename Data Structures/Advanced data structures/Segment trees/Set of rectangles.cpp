#include<bits/stdc++.h>
using namespace std;
int n, q, a[200121], b[200121], c[200121], d[200121], w[200121], result[200121], t[2001210];
vector<pair<int, pair<int, int>>> events;
 
void upd(int v, int tl, int tr, int pos, int value)
{
    if(tl > pos || tr < pos)
        return;
    t[v] = max(t[v], value);
    if(tl == tr)
        return;
    int tm = (tl + tr) >> 1, L = v << 1, R = L | 1;
    upd(L, tl, tm, pos, value);
    upd(R, tm + 1, tr, pos, value);
}
 
int get(int v, int tl, int tr, int l, int r)
{
    if(tl > r || tr < l) 
        return 0;
    if(tl >= l && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1, L = v << 1, R = L | 1;
    return max(get(L, tl, tm, l, r), get(R, tm + 1, tr, l, r));
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        w[i] = a[i];
    }
    sort(w, w + n);
    for(int i = 0; i < q; ++i)
        cin >> c[i] >> d[i];
    for(int i = 0; i < n; ++i)
        events.push_back({b[i], {0, -a[i]}});
    for(int i = 0; i < q; ++i)
        events.push_back({d[i],{1, i}});
    sort(events.begin(), events.end());
    for(int i = 0; i < (int)events.size(); ++i)
    {
        pair<int,pair<int,int> > p = events[i];
        if(p.second.first == 0)
        {
            int pos = lower_bound(w, w + n, -p.second.second) - w;
            int value = get(1, 0, 200010, pos, n - 1);
            upd(1, 0, 200010, pos, value + 1);
        }
        else
        {
            int pos = lower_bound(w, w + n, c[p.second.second]) - w;
            result[p.second.second] = get(1, 0, 200010, pos, n - 1);
        }
    }
    for(int i = 0; i < q; ++i)
        cout << result[i] << "\n";
    return 0;
}
