#include <bits/stdc++.h>
using namespace std;
typedef array<int, 2> vec;
typedef array<vec, 2> mat;
  
struct node 
{
    long long w, fw, fwp1, fwm1,  t, r, rm1, l, lp1;
};vector<node> tree;
 
mat prod(const mat& a, const mat & b) 
{
    mat c;
    c[0][0] = ((long long)(a[0][0]) * b[0][0] + (long long)(a[0][1]) * b[1][0]) % 1000000007;
    c[0][1] = ((long long)(a[0][0]) * b[0][1] + (long long)(a[0][1]) * b[1][1]) % 1000000007;
    c[1][0] = ((long long)(a[1][0]) * b[0][0] + (long long)(a[1][1]) * b[1][0]) % 1000000007;
    c[1][1] = ((long long)(a[1][0]) * b[0][1] + (long long)(a[1][1]) * b[1][1]) % 1000000007;
    return c;
}vector<mat>fibo;
     
mat fib(long long n) 
{
    mat res = fibo[0];
    int i = 1;
    while(n) 
    {
        if(n & 1) 
            res = prod(res, fibo[i]); 
        i++;
         n >>= 1;
    }
    return res;
}
     
node combine(const node & a, const node & b) 
{
    node c;
    c.w = a.w + b.w;
    c.fw = (a.fw * b.fwp1 + a.fwm1 * b.fw) % 1000000007;
    c.fwm1 = (a.fw * b.fw + a.fwm1 * b.fwm1) % 1000000007;
    c.fwp1 = c.fwm1 + c.fw;
    c.t = (a.t + b.t + a.r * b.lp1 + a.rm1 * b.l) % 1000000007;
    c.r = (b.r + a.r * b.fwp1 + a.rm1 * b.fw) % 1000000007;
    c.l = (a.l + a.fw * b.lp1 + a.fwm1 * b.l ) % 1000000007;
    c.rm1 = (b.rm1 + a.r * b.fw + a.rm1 * b.fwm1) % 1000000007;
    c.lp1 = (a.lp1 + a.fwp1 * b.lp1 + a.fw * b.l) % 1000000007;
    return c;  
}
     
struct SegTree 
{
    vector<node> tree;
    int n;
    SegTree(const vector<long long>& Arg) 
    { 
        n = Arg.size();
        tree.resize(2 * n);
        for(int i = 0 ; i < n; i++) 
        {  
            mat f = fib(Arg[i]);
            tree[n + i].w = Arg[i];
            tree[n + i].fw = tree[n + i].r = tree[n + i].l = tree[n + i].t = f[0][1];
            tree[n + i].fwm1 = tree[n + i].rm1 = f[1][1];
            tree[n + i].fwp1 = tree[n + i].lp1 = f[0][0];      
        }
        for(int i = n - 1; i > 0; --i) 
            tree[i] = combine(tree[i<<1] , tree[i<<1|1]);
    }
    void modify(int p, long long value) 
    {  
        node x;
        x.w = value;
        mat f = fib(value);
        x.fw = x.r = x.l = x.t = f[0][1];
        x.fwm1 = x.rm1 = f[1][1];
        x.fwp1 = x.lp1 = f[0][0];
        for(tree[p += n] = x; p >>= 1; ) 
            tree[p] = combine(tree[p<<1], tree[p<<1|1]);
    }
    node query(int l, int r) 
    {  
        node resl, resr;  
        resl.w = 0;
        resl.lp1 = resl.rm1 = resl.fw = resl.l = resl.r = resl.t = 0;
        resl.fwp1 = resl.fwm1 = 1;
        resr = resl;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) 
        {
            if(l & 1) 
                resl = combine(resl, tree[l++]);
            if(r & 1) 
                resr = combine(tree[--r], resr);
        }
        return combine(resl, resr);
    } 
};
     
int main()  
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fibo = vector<mat>(64);
    fibo[0] = {vec{1, 0}, vec{0, 1}}, fibo[1] = {vec{1, 1}, vec{1, 0}};
    for(int i = 2; i < 64; i++)
        fibo[i] = prod(fibo[i - 1], fibo[i - 1]);
    int n, q; 
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    SegTree tree(a);
    cin >> q;
    while(q--) 
    {
        int t;
        cin >> t;
        if(t == 2) 
        {
            int l, r;
            cin >> l >> r;
            cout <<  tree.query(l-1, r).t << endl;
        }
        else 
        {
            int pos; 
            long long val;
            cin >> pos >> val;
            tree.modify(pos-1, val);
        }
    }
}
