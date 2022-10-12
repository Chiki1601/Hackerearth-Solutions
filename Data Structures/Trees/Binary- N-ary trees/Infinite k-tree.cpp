#include <bits/stdc++.h>
using namespace std;
 
void fun1(long long u, long long v, long long k, map<pair<long long, long long>, long long>& mp)
{
    long long ans = 0;
    while(u != v)
    {
        if(u > v)
        {
            long long pre = u;
            u /= k;
            if(mp.count({pre, u}) != 0)
                ans += mp[{pre, u}];
            else 
				ans += 1;
        }
        else
        {
            long long pre = v;
            v /= k;
            if(mp.count({pre, v}) != 0)
                ans += mp[{pre, v}];
            else 
				ans += 1;
        }
    }
    cout << ans << endl;
    return;
}
 
void fun2(long long u, long long v, long long w, long long k, map<pair<long long, long long>, long long>& mp)
{
    while(u != v)
    {
        if(u > v)
        {
            long long pre = u;
            u /= k;
            if(mp.count({pre, u}) != 0)
                mp[{pre, u}] += w;
            else
                mp[{pre, u}] = w + 1;
        }
        else
        {
           long long pre = v;
            v /= k;
            if(mp.count({pre,v}) != 0)
                mp[{pre, v}] += w;
            else
                mp[{pre, v}] = w + 1;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long k, q; 
	cin >> k >> q;
    map<pair<long long, long long>, long long> mp;
    while(q--)
    {
        long long n; 
		cin >> n;
        if(n == 1)
        {
            long long u, v; 
			cin >> u >> v;
            fun1(u, v, k, mp);
        }
        else
        {
            long long u, v, w; 
			cin >> u >> v >> w;
            fun2(u, v, w, k, mp);
        }
    }
}
