#include <bits/stdc++.h>
using namespace std;
long long tree[3000005], a[1000005], f[500005];
 
void build(long long idx, long long start, long long end)
{
    if(start == end) 
        tree[idx] = f[a[start]];
    else
    {
        long long mid = (start + end) / 2;
        build(2 * idx, start, mid);
        build(2 * idx + 1, mid + 1, end);
        tree[idx] = (tree[2 * idx] + tree[2 * idx + 1]) % 1000000007;
    }
}
 
void update(long long idx, long long start, long long end, long long x, long long y)
{
    if(start == end)
    {
        tree[idx] = f[y];
        a[x] = y;
    }
    else
    {
        long long mid = (start + end) / 2;
        if(start <= x && x <= mid) 
            update(2 * idx, start, mid, x, y);
        else 
            update(2 * idx + 1, mid + 1, end, x, y);
        tree[idx] = (tree[2 * idx] + tree[2 * idx + 1]) % 1000000007;
    }
}
 
long long query(long long idx, long long start, long long end, long long l, long long r)
{
    if(start > r || end < l) 
        return 0;
    else if(l <= start && end <= r) 
        return tree[idx];
    long long mid = (start + end) / 2;
    long long p1 = query(2 * idx, start, mid, l, r), p2 = query(2 * idx + 1, mid + 1, end, l, r);
    return (p1 + p2) % 1000000007;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, q, l, r, i, j, p[500005], phi[500005];
    for(i = 2; i < 500005; i++) 
        p[i] = 1;
    for(i = 2; i <= sqrt(500005); i++)
    {
        if(p[i])
        {
            for(j = 2 * i; j < 500005; j += i) 
                p[j] = 0;
        }
    }
    for(i = 1; i < 500005; i++) 
        phi[i] = i;
    for(i = 1; i < 500005; i++)
    {
        if(p[i])
        {
            for(j = i; j < 500005; j += i) 
                phi[j] -= phi[j] / i;
        }
    }
    for(i = 1; i < 500005; i++)
    {
        for(j = i; j < 500005; j += i)
            f[j] += i * phi[i];
        f[i] = (f[i] + 1) / 2;
    }
    cin >> n;
    char qt;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while(q--)
    {
        cin >> qt >> l >> r;
        if(qt == 'C')
            cout << query(1, 1, n, l, r) << endl;
        else if(qt == 'U') 
            update(1, 1, n, l, r);
    }
    return 0;
}    
