#include<bits/stdc++.h>
using namespace std;
int f[2000010], n, m, mx;
pair<pair<int,int>,int> a[2000010];
pair<long long,int> t[40000010];
long long ans[2000010];

void upd(int v,int tl,int tr,int pos)
{
    if(tl > pos || tr < pos)
        return;
    t[v].first += pos;
    ++t[v].second;
    if(tl == tr)
        return;
    int tm = (tl + tr) >> 1,
        L = v << 1,
        R = L | 1;
    upd(L, tl, tm, pos);
    upd(R, tm + 1, tr, pos);
}

long long get(int k)
{
    int v = 1, tl = 1, tr = 10000000;
    long long ans = 0;
    while(tl < tr)
    {
        int L = v << 1, R = L | 1, tm = (tl + tr) >> 1;
        if(t[R].second < k)
        {
            ans += t[R].first;
            k -= t[R].second;
            v = L;
            tr = tm;
        }
        else
        {
            v = R;
            tl = tm + 1;
        }
    }
    ans += tl *1ll* k;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i <= 2000000; ++i)
    {
        for(int j = i; j <= 2000000; j += i)
        {
            f[j] += i;
            mx = max(mx, f[j]);
        }
    }
    int t, last = 0;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a + 1, a + t + 1);
    for(int i = 1; i <= t; ++i)
    {
        for(int j = last + 1; j <= a[i].first.first; ++j)
            upd(1, 1, 10000000, f[j]);
        last = a[i].first.first;
        ans[a[i].second] = get(a[i].first.second);
    }
    for(int i = 1; i <= t; ++i)
        cout << ans[i] << "\n";
    return 0;
}
