#include <bits/stdc++.h>
using namespace std; 
long long p2[200005], i2[200005], fen[200005];
 
long long modpow(long long a, long long b)
{
    long long res = 1;
    while(b)
    {
        if(b & 1) 
            res = (res * a) % 1000000007;
        a = (a * a) % 1000000007;
        b >>= 1;
    }
    return res;
}
 
void update(int x, long long v)
{
    ++x;
    while(x < 200005)
    {
        fen[x] = (fen[x] + v) % 1000000007;
        x += (x & (-x));
    }
}
 
long long query(int x)
{
    ++x;
    long long res = 0;
    while(x)
    {
        res += fen[x];
        x -= (x & (-x));
    }
    return res % 1000000007;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    p2[0] = 1;
    for(int i = 1; i < 200005; i++) 
        p2[i] = (p2[i - 1] * 2) % 1000000007;
    i2[200004] = modpow(p2[200004], 1000000005);
    for(int i = 200003; i >= 0; i--) 
        i2[i] = (i2[i + 1] * 2) % 1000000007;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1') 
            update(i, p2[n - i - 1]);
    }
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x;
            char c;
            cin >> x;
            --x;
            if(s[x] == '0')
                update(x, p2[n - x - 1]);
            else
                update(x, 1000000007 - p2[n - x - 1]);
            s[x] ^= 1;
        } 
        else
        {
            int l, r;
            cin >> l >> r;
            --l, --r;
            long long res = query(r);
            if(l) 
                res = (res - query(l - 1) + 1000000007) % 1000000007;
            if(r != n - 1) 
                res = (res * i2[n - r - 1]) % 1000000007;
            cout << res << "\n";
        }
    }
}  
