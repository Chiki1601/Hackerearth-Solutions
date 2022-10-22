#include <bits/stdc++.h>
using namespace std;
 
inline int msb(int64_t x) 
{ 
    return 63-__builtin_clzll(x); 
}
 
inline int64_t bitwise_AND(int64_t l, int64_t r) 
{
    return msb(l) == msb(r) ? l&~((1ll<<(msb(l ^ r) + 1)) - 1) : 0; 
}
 
inline int64_t solve(int64_t l, int64_t r, int64_t k) 
{
    if(k == 1)
        return r;
    const int64_t m = 1ll<<msb(r), u = m - 1, v = k - 1;
    if(r - l == v)
        return bitwise_AND(l, r);
    int64_t ans = 0;
    if(u - l >= v)
        ans = max(ans, bitwise_AND(u - v, u));
    if(r - m >= v)
        ans = max(ans, bitwise_AND(r - v, r));
    return ans; 
}
 
int main() 
{ 
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int Q;
    cin >> Q;
    for(int64_t l, r, k; Q--; cout << solve(l, r, k) << "\n")
        cin >> l >> r >> k;
    return 0; 
}
