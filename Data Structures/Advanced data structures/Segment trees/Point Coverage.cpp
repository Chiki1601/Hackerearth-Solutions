#include<bits/stdc++.h>
using namespace std;
int n, q, a[200010], ans[200010], l[200010], r[200010], x[200010];
 
template <typename T> class fenwick 
{
    vector<T> bit; 
    int N;
    public:
        fenwick(int n) 
        { 
            N = n + 5;
            bit.resize(N);
        }
        void add(int i, T val) 
        {
            while (i < N) 
            { 
                bit[i] += val; 
                i += (i & -i);
            } 
        }
        T query(int i) 
        { 
            T ans(0); 
            while (i > 0) 
            { 
                ans += bit[i]; 
                i -= (i & -i); 
            }  
            return ans;
        } 
};
 
struct tup 
{
    int p, q, r;
};
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    set<int> st;
    for(int i = 1; i <= n; ++i) 
        cin >> a[i];
    for(int i = 1; i <= q; ++i) 
        cin >> l[i] >> r[i] >> x[i];
    vector<tup> v;
    for(int i = 1; i + 1 <= n; ++i) 
    {
        v.push_back({min(a[i], a[i + 1]), 1, i});
        v.push_back({max(a[i], a[i + 1]), 3, i});
    }
    for(int i = 1; i <= q; ++i) 
        v.push_back({x[i], 2, i});
    sort(v.begin(), v.end(), [&](tup & a, tup & b) 
    {
        return make_pair(a.p, a.q) < make_pair(b.p, b.q);
    });
    fenwick<int> f(200010);
    for(auto &u : v) 
    {
        if(u.q == 1) 
            f.add(u.r, 1);
        else if(u.q == 2) 
            ans[u.r] = f.query(r[u.r]) - f.query(l[u.r] - 1);
        else 
            f.add(u.r, -1);
    }
    for(int i = 1; i <= q; ++i) 
        cout << ans[i] << "\n";
}
