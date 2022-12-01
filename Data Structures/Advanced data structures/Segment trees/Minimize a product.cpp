#include <bits/stdc++.h>
using namespace std;
 
struct Node 
{
    int mn, ct, pos;
};const Node unit = {1000000007, 0, -1};
 
template<class T> struct SegTree 
{
    T f(T a, T b) 
    { 
        if (a.mn == b.mn) 
            a.ct += b.ct;
        else if (a.mn > b.mn) 
            a = b;
        return a;
    }
    vector<T> s; 
    int n;
    SegTree(int _n = 0, T def = unit) : s(2 * _n, def), n(_n) {}
    void update(int pos, T val) 
    {
        for(s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) 
    {
        T ra = unit, rb = unit;
        for(b += n, e += n; b < e; b /= 2, e /= 2) 
        {
            if(b % 2) 
                ra = f(ra, s[b++]);
            if(e % 2) 
                rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while(t--) 
    {
        int n, q; 
        cin >> n >> q;
        vector<int> a(n);
        for(int &x : a)
            cin >> x;
        SegTree<Node> T(n);
        for(int i = 0; i < n; ++i) 
            T.update(i, Node{a[i], 1, i});
        long long int ans = 0;
        while(q--) 
        {
            int type; 
            cin >> type;
            if(type == 1) 
            {
                int pos, val; 
                cin >> pos >> val; 
                --pos;
                T.update(pos, Node{val, 1, pos});
            }
            else 
            {
                int L, R; 
                cin >> L >> R; 
                --L;
                auto res = T.query(L, R);
                if(res.ct == 1) 
                {
                    int m = res.pos;
                    auto left = T.query(L, m);
                    auto right = T.query(m + 1, R);
                    if(left.mn == right.mn) 
                        ans = (ans + left.ct + right.ct) % 1000000007;
                    else if (left.mn < right.mn) 
                        ans = (ans + left.ct) % 1000000007;
                    else 
                        ans = (ans + right.ct) % 1000000007;
                }
                else 
                {
                    long long int add = (1LL * res.ct * (res.ct - 1)) / 2;
                    ans = (ans + add) % 1000000007;
                }
            }
        }
        cout << ans << endl;
    }
}
