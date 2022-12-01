#include <bits/stdc++.h>
using namespace std;
int combi[16][16], vp[1 << 17 << 1][12], vd[1 << 17 << 1];
 
void calc(int* s, int d, int* t) 
{
    if(d < 1) 
    {
        for(int i = 0; i <= 10; ++i) 
            t[i] = s[i];
        return;
    }
    long long pd[12] = {1};
    for(int i = 1; i <= 10; ++i) 
        pd[i] = pd[i - 1] * d % 1000000007;
    for(int i = 10; i >= 0; --i) 
    {
        t[i] = s[i];
        for(int j = i; j-- > 0; ) 
            (t[i] += (long long)s[j] * combi[i][j] % 1000000007 * pd[i - j] % 1000000007) %= 1000000007;
    }
}
 
void update(int b, int e, int d, int p, int u, int w) 
{
    if(d < 1) 
        return;
    vp[p][0] = -1;
    if(b <= u && e >= u + w) 
    {
        (vd[p] += d) %= 1000000007;
        return;
    }
    w >>= 1;
    int p1 = p << 1;
    if(b < u + w) 
        update(b, e, d, p1, u, w);
    if(e > u + w) 
        update(b, e, d, p1 + 1, u + w, w);
}
 
int query(int b, int e, int r, int d, int p, int u, int w) 
{
    if(w < 2) 
    {
        if(vp[p][0] < 0) 
        {
            vp[p][0] = 1;
            for(int i = 1; i <= 10; ++i) 
                vp[p][i] = (long long)vp[p][i - 1] * vd[p] % 1000000007;
        }
        int t[12];
        calc(vp[p], d, t);
        return t[r];
    }
    int p1 = p << 1;
    if(b <= u && e >= u + w) 
    {
        if(vp[p][0] < 0) 
        {
            w >>= 1;
            int ret = query(b, e, r, (d + vd[p]) % 1000000007, p1, u, w), t[12];
            ret += query(b, e, r, (d + vd[p]) % 1000000007, p1 + 1, u + w, w);
            for(int i = 0; i <= 10; ++i) 
                t[i] = (vp[p1][i] + vp[p1 + 1][i]) % 1000000007;
            calc(t, vd[p], vp[p]);
            return ret % 1000000007;
        }
        {
            int t[12];
            calc(vp[p], d, t);
            return t[r];
        }
    }
    w >>= 1;
    int ret = 0;
    if(b < u + w) 
        ret += query(b, e, r, (d + vd[p]) % 1000000007, p1, u, w);
    if(e > u + w) 
        ret += query(b, e, r, (d + vd[p]) % 1000000007, p1 + 1, u + w, w);
    return ret % 1000000007;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    for(int i = 0; i < 16; ++i) 
    {
        combi[i][0] = combi[i][i] = 1;
        for(int j = 1; j < i; ++j) 
            combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % 1000000007;
    }
    int T, n;
    cin >> T;
    while(T-- > 0 && cin >> n) 
    {
        int w = 1, q;
        while(w < n) 
            w <<= 1;
        for(int i = 0; i < n && cin >> vd[w + i]; ++i) 
            vp[w + i][0] = -1;
        for(int i = w; i-- > 0; ) 
        {
            vd[i] = 0;
            vp[i][0] = -1;
        }      
        cin >> q;
        for(int i = 0, o, x, y, z; i < q && cin >> o; ++i) 
        {
            if(1 == o) 
            {
                cin >> x >> z;
                update(x - 1, x, z, 1, 0, w);
            } 
            else if(2 == o) 
            {
                cin >> x >> y >> z;
                update(x - 1, y, z, 1, 0, w);
            } 
            else 
            {
                cin >> x >> y >> z;
                cout << query(x - 1, y, z, 0, 1, 0, w) << endl;
            }
        }
    } 
    return 0;
}
