#include<bits/stdc++.h>
using namespace std;
int n, m, cp, sz1, sz2, l[500025], r[500025], last, c1[500025], c2[500025];
string st1[100005], st2[100005], Z;
long long ans, TTL, pw[1<<21], s[1<<21];
 
void remove_block(int l, int r)
{
    TTL -= 1ll * c1[l] * c2[l];
}
 
void add_block(int l, int r)
{
    TTL += 1ll * c1[l] * c2[l];
}
 
long long eval(int ps, int span)
{
    return (s[ps + span] - s[ps]) * pw[(1<<20) - ps];
}
 
int lcp(int a, int b)
{
    if (a < b)
        swap(a, b);
    int l = 0, r;
    r = Z.size() - b;
    while (l < r)
    {
        int mid = l + r + 1;
        mid /= 2;
        if (eval(a, mid) == eval(b, mid))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
 
bool cmp(int a, int b)
{
    int l = lcp(a, b);
    if (a + l == Z.size())
        return true;
    if (b + l == Z.size())
        return false;
    return (Z[a + l] < Z[b + l]);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pw[0] = 1;
    for(int i = 1; i <= (1<<20); i++)
        pw[i] = pw[i - 1] * 173;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> st1[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> st2[i];
    for(int i = 1; i <= n; i++)
    {
        Z += st1[i];
        sz1 += st1[i].size();
        Z += "*";
    }
    cp = Z.size();
    for(int i = 1; i <= m; i++)
    {
        Z += st2[i];
        sz2 += st2[i].size();
        Z += "#";
    }
    vector<int> v;
    for(int i = 1; i <= Z.size(); i++)
        s[i] = s[i - 1] + Z[i - 1] * pw[i];
    for(int i = 0; i < Z.size(); i++)
        v.push_back(i);
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++)
    {
        l[i] = i;
        r[i] = i;
        if(Z[v[i]] >= 'a' && Z[v[i]] <= 'z')
        {
            if(v[i] < cp)
                c1[i] = 1;
            else
                c2[i] = 1;
        }
    }
    vector<pair<int, int>> events;
    for(int i = 0; i + 1 < v.size(); i++)
    {
        int val = lcp(v[i], v[i + 1]);
        events.push_back(make_pair(val, i));
    }
    sort(events.begin(), events.end());
    reverse(events.begin(), events.end());
    last = 1000000000;
    for(int i = 0; i < events.size(); i++)
    {
        int val = events[i].first, ps = events[i].second;
        ans += TTL * 1ll * (last - val);
        last = val;
        remove_block(l[ps], ps);
        remove_block(ps + 1, r[ps + 1]);
        l[r[ps + 1]] = l[ps];
        r[l[ps]] = r[ps + 1];
        c1[l[ps]] += c1[ps + 1];
        c2[l[ps]] += c2[ps + 1];
        add_block(l[ps], r[l[ps]]);
    }
    ans += 1ll * last * TTL;
    cout << ans << endl;
    return 0;
}
