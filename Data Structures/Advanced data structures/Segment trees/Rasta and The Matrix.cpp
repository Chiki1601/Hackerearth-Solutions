#include <bits/stdc++.h>
using namespace std;
int n, nn;
struct Seg* segs;
 
struct Seg 
{
    long long o;
    bool f;
    int s;
    Seg() {}
    void init() 
	{
        o = 0, f = false, s = 0;
    }
    void push(long long w) 
	{
        return;  
        if(!f) 
			return;
        f = false;
        o = w - o;
        if(s > 0) 
		{
            segs[s].f ^= true;
            segs[s + 1].f ^= true;
        }
    }
    long long val(long long w) 
	{
        return f ? (w - o) : o;
    }
    long long update(long long l, long long r, long long u = 0, long long w = 1LL << 60) 
	{
        if(l <= u && u + w <= r) 
		{
            f = !f;
            return f ? (w - o - o) : (o + o - w);
        }
        if(w < 2) 
		{
            cout << "error!!!" << "\n";
            return 0;
        }
        long long w1 = w >> 1;
        if (s == 0) 
		{
            s = nn;
            nn += 2;
            segs[s].init();
            segs[s + 1].init();
        }
        push(w);
        long long delta = 0;
        if(l < u + w1) 
			delta += segs[s].update(l, r, u, w1);
        if(r > u + w1) 
			delta += segs[s + 1].update(l, r, u + w1, w1);
        o += delta;
        return f ? -delta : delta;
    }
    long long query(long long l, long long r, long long u = 0, long long w = 1LL << 60) 
	{
        if(l <= u && u + w <= r) 
		{
            return val(w);
        }
        push(w);
        if(0 == o) 
			return f ? (min(r, u + w) - max(l, u)) : 0;
        if(w == o) 
			return f ? 0 : (min(r, u + w) - max(l, u));
        long long ret = 0, w1 = w >> 1;
        if(l < u + w1) 
			ret += segs[s].query(l, r, u, w1);
        if(r > u + w1) 
			ret += segs[s + 1].query(l, r, u + w1, w1);
        return f ? (min(r, u + w) - max(l, u) - ret) : ret;
    }
} segs_[12812800];
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    segs = segs_;
    segs[0].init();
    segs[1].init();
    nn = 2;
    long long x, y, l, r, last = 0;
    for(int i = 0, o; i < n && cin >> o; ++i) 
	{
        if(nn >= 12812700) 
		{
            cout << "error!" << "\n";
            break;
        }
        if(1 == o) 
		{
            cin >> x >> l >> r;
            l ^= last;
            r ^= last;
            if(l > r) 
				swap(l, r);
            segs[x].update(l, r + 1);
        } 
		else 
		{
            cin >> x >> y >> l >> r;
            x ^= last;
            y ^= last;
            l ^= last;
            r ^= last;
            if(x > y) 
				swap(x, y);
            if(l > r) 
				swap(l, r);
            long long a = segs[0].query(x, y + 1) % 1000000007, b = segs[1].query(l, r + 1) % 1000000007;
            if(a < 0 || b < 0 || a > y + 1 - x || b > r + 1 - l) 
				cout << "error: " << a << " " << y + 1 - x << " " << b << " " << r + 1 - l << "\n";
            last = ((r + 1 - l - b) % 1000000007 * a % 1000000007 + (y + 1 - x - a) % 1000000007 * b % 1000000007) % 1000000007;
            cout << last << "\n";
        }
    }
    return 0;
}
