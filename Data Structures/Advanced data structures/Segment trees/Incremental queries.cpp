#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int mx, cnt[2];
    long long sum;
    Node()
	{
        mx = sum = cnt[0] = cnt[1] = 0;
    }
    Node(int x)
	{
        sum = mx = x;
        cnt[x % 2] = 1;
        cnt[!(x % 2)] = 0;
    }
    long long ans()
	{
        return (mx * (long long)(cnt[0] + cnt[1]) - sum) / 2 + (cnt[!(mx % 2)] + 1) / 2;
    }
    Node operator +(Node o) const
	{
        o.mx = max(o.mx, mx);
        o.sum = o.sum + sum;
        o.cnt[0] += cnt[0];
        o.cnt[1] += cnt[1];
        return o;
    }
}  seg[1000028];
int n, q;
 
void upd(int p, int x)
{
    for(seg[p += n] = x; p >>= 1;)
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
}
 
Node get(int l, int r)
{
    Node ans;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
        if(l % 2)
            ans = seg[l++] + ans;
        if(r % 2)
            ans = ans + seg[--r];
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = n; i < 2 * n; i++)
	{
        int x;
        cin >> x;
        seg[i] = x;
    }
    for(int i = n - 1; i > 0; i--)
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    while(q--)
	{
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if(t == 1)
            upd(l, r);
        else
            cout << get(l, r).ans() << endl;
    }
}
