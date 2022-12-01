#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long, int>, null_type, less< pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update>
long long POWER[65], ar[100005];
bool is[400020];
ordered_set v[400020];
 
long long power(long long a, long long b) 
{
    long long ret = 1;
    while(b) 
    {
        if(b & 1) 
            ret *= a; 
        a *= a;
        if(ret >= 1000000007) 
            ret %= 1000000007;
        if(a >= 1000000007) 
            a %= 1000000007;
        b >>=1;
    }
    return ret;
}
 
bool overflow(long long x, long long y) 
{
    long long val = (1000005000 + y - 1) / y;
    if(x >= val) 
        return true;
    return false;
}
 
void go(int idx, pair<long long,int> f1, pair<long long,int> f2) 
{
    while(idx) 
    {
        v[idx].erase(f1);
        v[idx].insert(f2);
        idx/=2;
    }
}
 
void build(int node, int start, int end) 
{
    v[node].clear();
    is[node] = false;
    if(start == end) 
    {
        v[node].insert(make_pair(ar[start], start));
        return;
    }
    int mid = (start + end) >> 1, oth = 2 * node, prim = 2 * node + 1;
    build(2 * node, start, mid);
    build(2 * node + 1,mid + 1, end);
    if(((int)v[prim].size()) < ((int)v[oth].size())) swap(prim,oth);
        v[node] = v[prim];
    for(auto it : v[oth]) 
        v[node].insert(it);
}
 
void multiply(int node, int start, int end, int qs, int qe, long long val) 
{
    if(start > end or qe < start or qs > end) 
        return;
    if(is[node]) 
        return;
    if(start == end) 
    {
        if(overflow(ar[start], val)) 
        {
            is[node] = true;
            go(node, make_pair(ar[start], start), make_pair(1000005000, start));
            ar[start] = 1000005000;
            return;
        }
        go(node, make_pair(ar[start], start), make_pair(ar[start] * val, start));
        ar[start] *= val;
        return;
    }
    int mid = (start + end) >> 1;
    multiply(2 * node, start, mid, qs, qe, val);
    multiply(2 * node + 1, mid + 1, end, qs, qe, val);
    is[node] = is[2 * node] & is[2 * node + 1];
}
 
int query(int node, int start, int end, int qs, int qe, long long val)
{
    if(start > end or qe < start or qs > end) 
        return 0;
    if(start >= qs and end <= qe) 
        return end - start + 1 - v[node].order_of_key(make_pair(val, 0));
    int mid = (start + end) >> 1;
    return query(2 * node, start, mid, qs, qe, val) + query(2 * node + 1, mid + 1, end, qs, qe, val);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    POWER[0] = 1;
    for(int i = 1; i < 63; i++) 
        POWER[i] = POWER[i - 1]<<1LL;
    int n, q;
    cin >> n >> q;
    assert(n >= 1 and n <= 50000);
    assert(q >= 1 and q <= 100000);
    for(int i = 1; i <= n; i++) 
        cin >> ar[i];
    build(1, 1, n);
    while(q--) 
    {
        int type, l, r;
        cin >> type >> l >> r;
        assert(type == 1 or type == 2);
        assert(l >= 1 and l <= n);
        assert(r >= 1 and r <= n);
        long long x, y;
        cin >> x;
        assert(x >= 2 and x <= 1000000000);
        if(type == 1) 
            multiply(1, 1, n, l, r, x);
        if(type == 2) 
        {
            long long y;
            cin >> y;
            assert(y >= 1 and y <= 1000000000);
            cout << query(1, 1, n, l, r, (y + x - 1) / x) << endl;
        }
    }
    return 0;
}
