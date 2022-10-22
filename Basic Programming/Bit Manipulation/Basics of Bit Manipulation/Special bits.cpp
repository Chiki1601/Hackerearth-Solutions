#include<bits/stdc++.h>
using namespace std;
 
bool is_true(string s, long long r)
{
    long long l = 0, po = 1;
    for(int i = 61; i >= 0; i--)
    {
        if(s[i] == '1')
            l += po;
        	  po *= 2;
    }
    if(l <= r)
        return true;
    return false;
}
 
long long to_long(string s)
{
    long long l = 0, po = 1;
	  for(int i = 61; i >= 0; i--)
    {
        if(s[i] == '1')
            l += po;
            po *= 2;
    }
    return l;
}
 
long long more_bit(long long l, long long r, long long k, long long l_bits)
{
    string sl = bitset<62>(l).to_string();
    for(int i = 61; i >= 0; --i)
    {
        if(sl[i] == '0')
        {
            sl[i] = '1';
            l_bits++;
        }
        if(is_true(sl, r) && l_bits == k)
            return to_long(sl);
    }
    return -1;
}
 
long long less_bit(long long l, long long r, long long k, long long l_bits)
{
    long long co = 0;
    string sl = bitset<62>(l).to_string();
    for(int i = 61; i >= 0; i--)
    {
        if(sl[i] == '1')
            co++;
        if(sl[i] == '0')
        {
            string s = sl;
            s[i] = '1';
            for(int j = i + 1; j < 62; ++j)
                s[j] = '0';
            if(is_true(s, r) && l_bits - co + 1 == k)
                return to_long(s);
            if(is_true(s, r) && l_bits - co + 1 < k)
                return more_bit(to_long(s), r, k, l_bits - co + 1);
        }
    }
    return -1;
}
 
long long fun(long long l, long long r, long long k)
{
    string sl = bitset<62>(l).to_string();
    string sr = bitset<62>(r).to_string();
    int set_bit = 0;
    for (int i = 0; i < 62; ++i)
    {
        if (sl[i] != sr[i])
            break;
        if (sl[i] == '1')
            set_bit++;
    }
    if (set_bit > k)
        return -1;
    int l_set_bit = 0;
    for (int i = 0; i < 62; ++i)
    {
        if (sl[i] == '1')
            l_set_bit++;
    }
    if (l_set_bit < k)
        return more_bit(l, r, k, l_set_bit);
    if (l_set_bit == k)
        return l;
    return less_bit(l, r, k, l_set_bit);
}
 
void solve() 
{
    long long n, l, r, k;
    cin >> l >> r >> k;
    cout << fun(l, r, k) << endl;
}
 
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}
