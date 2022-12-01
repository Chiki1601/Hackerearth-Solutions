#include <bits/stdc++.h>
using namespace std;
pair<int, long long> fen[2][100005];
 
template <typename T> inline void read(T& x)
{
    bool Neg = false;
    char c;
    for(c = getchar(); c < '0' | c > '9'; c = getchar())
        if(c == '-') 
            Neg = !Neg;
    x = c - '0';
    for(c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if(Neg) 
        x = -x;
}
 
template <typename T> inline void write(T x)
{
    if(x < 0)
        putchar('-'); x = -x;
    T p = 1;
    for(T temp = x / 10; temp > 0; temp /= 10) 
        p *= 10;
    for(; p > 0; x %= p, p /= 10) 
        putchar(x / p + '0');
}
 
void upd(int d, int p, pair<int, long long> v)
{
    for(int i = p; i < 100005; i+= i &-i)
        if(fen[d][i].first < v.first)
            fen[d][i] = v;
        else if(fen[d][i].first == v.first)
            fen[d][i].second = (fen[d][i].second + v.second) % 1000000007;
}
 
pair<int, long long> get(int d, int p)
{
    pair<int, long long> ret = {0, 0LL};
    for(int i = p; i > 0; i-= i &-i)
        if(ret.first < fen[d][i].first)
            ret = fen[d][i];
        else if(ret.first == fen[d][i].first)
            ret.second = (ret.second + fen[d][i].second) % 1000000007;
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, n;
    pair<int, int> a[100005];
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            int t = (x < 0) ? 0 : 1;
            a[i] = {abs(x), t};
        }
        pair<int, long long> res = {0, 0LL};
        for(int i = 1; i <= n; i++)
        {
            pair<int, long long> v = get(1 - a[i].second, a[i].first - 1);
            v.first++;
            if(!v.second) 
                v.second++;
            if(v.first > res.first)
                res = v;
            else if(v.first == res.first)
                res.second = (res.second + v.second) % 1000000007;
            upd(a[i].second, a[i].first, v);
        }
        cout << res.first << " " << res.second;
    }
}
