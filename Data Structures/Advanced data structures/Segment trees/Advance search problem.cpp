#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
unordered_map <string, ordered_set> cache;
unordered_set<int> vis;
string s;
 
void updateSet(ordered_set &o, int sign, int pos) 
{
    if(sign == -1) 
        o.erase(pos);
    else
        o.insert(pos);
}
 
void cacheStrings(int l, int r, int n, int m, int sign) 
{
    l = max(l, m - 1);
    for(int i = l; i < n and i - m + 1 <= r; ++i)
        updateSet(cache[s.substr(i - m + 1, m)], sign, i);
}
 
void updateAndValidateCache(int l, int r, int n, string &w) 
{
    for(auto z : vis)
        cacheStrings(l, r, n, z, -1);
    for(int i = l; i <= r; ++i) 
        s[i] = w[i - l];
    for(auto z : vis) 
        cacheStrings(l, r, n, z, 1);
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q >> s;
    while(q-- > 00) 
    {
        int t, l, r;
        string w;
        cin >> t >> l >> r >> w;
        l--, 
        r--;
        if(t == 1) 
        {
            if(!vis.count(w.size())) 
            {
                vis.insert(w.size());
                cacheStrings(0, n - 1, n, w.size(), 1);
            }
            auto &z = cache[w];
            int li = l + w.size() - 1;
            cout << z.order_of_key(r + 1) - z.order_of_key(li) << endl;
        } 
        else 
            updateAndValidateCache(l, r, n, w);
    }
    return 0;
}
