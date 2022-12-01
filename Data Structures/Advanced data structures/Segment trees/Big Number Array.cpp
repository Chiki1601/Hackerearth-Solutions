#include <bits/stdc++.h> 
using namespace std;
 
unsigned long long get(int i, const vector<unsigned long long>& v) 
{
    unsigned long long res = 0;
    while(i > 0) 
    {
        res ^= v[i];
        i &= i - 1;
    }
    return res;
}
 
void put(int i, unsigned long long a, vector<unsigned long long>& v) 
{
        int s = v.size();
        while(i < s) 
        {
            v[i] ^= a;
            i += (i & ~(i - 1));
        }
}
 
unsigned long long hush(unsigned long long k) 
{
    return k * 6364136223846793005ull + 1ull;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int tn = 0; tn < t; ++tn) 
    {
        int n, q;
        cin >> n >> q;
        vector<unsigned long long> ar(n + 1);
        for(int i = 0; i < q; ++i) 
        {
            int a;
            cin >> a;
            if (a == 1) 
            {
                int x, y, l, r;
                cin >> x >> y >> l >> r;
                unsigned long long z = hush(l - 1) ^ hush(r);
                put(x, z, ar);
                put(y + 1, z, ar);
            } 
            else 
            {
                int x, y;
                cin >> x >> y;
                cout << (get(x, ar) == get(y, ar) ? "YES\n" : "NO\n");
            }
        }
    } 
}
