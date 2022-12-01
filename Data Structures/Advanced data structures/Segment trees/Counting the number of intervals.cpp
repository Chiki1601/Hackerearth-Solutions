#include <bits/stdc++.h>
using namespace std;
vector<long long> t[2000036];
long long n, a[500009], q[500009], l[500009], r[500009], k, top;
 
struct node 
{
    int x, y, w;
};
 
void build(long long i = 1, long long l = 1, long long r = n) 
{
    if(l > r) 
        return;
    if(l == r) 
    {
        t[i].push_back(a[l]);
        return;
    }
    long long m = (l + r) >> 1;
    build(i << 1, l, m), build(i << 1 | 1, m + 1, r);
    t[i].resize(t[i << 1].size() + t[i << 1 | 1].size());
    merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(), t[i << 1 | 1].end(), t[i].begin());
}
 
long long get(long long u, long long v, long long x, long long i = 1, long long l = 1, long long r = n) 
{
    if(u > r || v < l) 
        return 0;
    if(u <= l && r <= v) 
    {
        long long cnt = upper_bound(t[i].begin(), t[i].end(), x) - t[i].begin();
        return cnt;
    }
    long long m = (l + r) >> 1;
    return get(u, v, x, i << 1, l, m) + get(u, v, x, i << 1 | 1, m + 1, r);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n + 1; i++)
    {
        while(top && a[i] <= a[q[top]]) 
        {
            r[q[top]] = i - 1;
            top--;
        }
        l[i] = q[top] + 1;
        q[++top] = i;
    }
    build();
    long long res = 0;
    for(int i = 1; i <= n; i++) 
    {
		if(i - l[i] <= r[i] - i) 
        {
			long long u = i, v = r[i];
			for(int j = l[i]; j <= i; j++)
                res += get(u, v, k - a[j] - a[i]);
		} 
        else 
        {
			int u = l[i], v = i;
			for(int j = i; j <= r[i]; j++)
                res += get(u, v, k - a[j] - a[i]);
		}
    }
    cout << res;
    return 0;
}
