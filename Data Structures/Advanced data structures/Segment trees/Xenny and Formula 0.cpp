#include<bits/stdc++.h>  
using namespace std;
int r, n;
long long a[100002], tree[100002], x, w, d, y;
 
void update(long long i, long long val) 
{
    while(i <= n) 
    {  
        tree[i] = (tree[i] + val) % 1000000007ll; 
        i += i & -i;
    }
}
 
long long query(long long i) 
{
    long long ret = 0;
    while (i > 0)
    {
        ret = (ret + tree[i]) % 1000000007ll;
        i -= i & -i;
    }
    return ret;
}
 
long long power(long long b, int p)
{
    if(!p) 
        return 1;
    long long ret = power(b, p>>1);
    return ret * ret % 1000000007ll * (p & 1 ? b : 1) % 1000000007ll;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while(r--) 
    {
        cin >> x >> w >> d >> y;
        long long k = w / d;
        long long dist = (w + (d + w % d)) * k / 2 + (w % d);
        long long ans = (a[n] + query(n)) % 1000000007ll * ((dist / n) % 1000000007ll) % 1000000007ll;
        dist %= n; 
        if(x + dist <= n) 
            ans = (ans + a[x + dist] - a[x - 1] + query(x + dist) - query(x - 1)) % 1000000007ll;
        else
            ans = (ans + a[n] - a[x - 1] + query(n) - query(x - 1) + a[x + dist - n] + query(x + dist - n)) % 1000000007ll;
        cout << ans << "\n";
        update(x, y);
    }
    return 0;
}
