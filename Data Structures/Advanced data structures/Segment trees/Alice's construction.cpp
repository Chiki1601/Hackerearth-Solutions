#include<bits/stdc++.h>
using namespace std;
 
struct my
{
    long long cntPref, cntSuff, cntAll, val;
    my()
    {
        cntPref = 0;
        cntSuff = 0;
        cntAll = 1;
        val = 1;
    }
};
 
long long f[100010], p[100010], pos[100010], answer[100010], rf[100010];
my t[400040];
vector<pair<pair<long long, long long>, long long>> q[100010];
 
long long BinPow(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans = ans * a % 1000000007;
        a = a * a % 1000000007;
        b >>= 1;
    }
    return ans;
}
 
my combine(my a, my b)
{
    my c = my();
    c.cntAll = a.cntAll + b.cntAll;
    if(b.cntPref > 0 && a.cntSuff > 0)
    {
        if(a.cntAll == a.cntSuff && b.cntAll == b.cntPref)
        {
            c.cntPref = c.cntAll;
            c.cntSuff = c.cntAll;
        }
        else
            if(a.cntAll == a.cntSuff)
            {
                c.cntPref = a.cntAll + b.cntPref;
                c.cntSuff = b.cntSuff;
            }
            else
                if(b.cntAll == b.cntPref)
                {
                    c.cntPref = a.cntPref;
                    c.cntSuff = b.cntAll + a.cntSuff;
                }
                else
                {
                    c.cntPref = a.cntPref;
                    c.cntSuff = b.cntSuff;
                }
                c.val = a.val * b.val % 1000000007 * rf[a.cntSuff] % 1000000007 * rf[b.cntPref] % 1000000007 * f[a.cntSuff + b.cntPref] % 1000000007;
    }
    else
    {
        c.cntPref = a.cntPref;
        c.cntSuff = b.cntSuff;
        c.val = (a.val * b.val) % 1000000007;
    }
    return c;
}
 
void upd(long long v, long long tl, long long tr, long long pos)
{
    if(tl > pos || tr < pos)
        return;
    if(tl == tr)
    {
        t[v].cntPref = t[v].cntSuff = t[v].cntAll = t[v].val = 1;
        return;
    }
    long long tm = (tl + tr) >> 1, L = v << 1, R = L | 1;
    upd(L, tl, tm, pos);
    upd(R, tm + 1, tr, pos);
    t[v] = combine(t[L], t[R]);
}
 
my get(long long v, long long tl, long long tr, long long l, long long r)
{
    if(tl >= l && tr <= r)
        return t[v];
    long long tm = (tl + tr) >> 1,
    L = v << 1,
    R = L | 1;
    if(r <= tm)
        return get(L, tl, tm, l, r);
    if(l > tm)
        return get(R, tm + 1, tr, l, r);
    my a1 = get(L, tl, tm, l, r),
    a2 = get(R, tm + 1, tr, l, r);
    my a3 = combine(a1, a2);
    return a3;
}
 
main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, m;
    cin >> n >> m;
    f[0] = 1;
    rf[0] = 1;
    for(long long i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] * i % 1000000007;
        rf[i] = BinPow(f[i], 1000000005);
    }
    for(long long i = 1; i <= 4 * n; ++i) 
        t[i] = my();
    for(long long i = 1; i <= n; ++i)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(long long i = 1; i <= m; ++i)
    {
        long long l, r, x;
        cin >> l >> r >> x;
        q[x].push_back({{l, r},i});
    }
    for(long long i = 1; i <= n; ++i)
    {
        upd(1, 1, n, pos[i]);
        for(long long j = 0; j < (long long)q[i].size(); ++j)
            answer[q[i][j].second] = get(1, 1, n, q[i][j].first.first, q[i][j].first.second).val;
    }
    for(long long i = 1; i <= m; ++i)
        cout << answer[i] << endl;
    return 0;
}
