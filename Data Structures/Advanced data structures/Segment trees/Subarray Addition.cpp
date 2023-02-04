#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
struct Fenwick 
{
    int n; 
    vector<int> t;
    Fenwick(int n_): n(n_), t(n_ + 1) {}
    void add(int i, int v) 
    { 
        for(; i <= n; i += i & -i) 
            t[i] += v; 
    }
    int sum(int i) 
    {
        int v = 0;
        for(; i > 0; i -= i & -i) 
            v += t[i]; 
        return v; 
    }
    int range_sum(int l, int r) 
    { 
        return sum(r) - sum(l - 1); 
    }
};
 
#undef int 
int main() 
{
#define int long long int
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q, sum = 0;
    cin >> n >> q;
    vector<int> a(n + 5), arr(n + 5);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    Fenwick bit(q + 5), bit1(q + 5);
    vector<pair<int, pair<int, int>>> vl[n + 5], vr[n + 5];
    for(int i = 1; i <= q; i++) 
    {
        int t;
        cin >> t;
        if(t == 1) 
        {
            int l, r, x;
            cin >> l >> r >> x;
            vl[l].push_back(make_pair(i, make_pair(x, 1)));
            vr[r + 1].push_back(make_pair(i, make_pair(x, 1)));
        } 
        else 
        {
            int l, r;
            cin >> l >> r;
            vl[l].push_back(make_pair(i, make_pair(0, 2)));
            vr[r + 1].push_back(make_pair(i, make_pair(0, 2)));
        }
    }
    for(int i = 1; i < n + 5; i++) 
    {
        if(vl[i].size() > 0) 
            sort(vl[i].rbegin(), vl[i].rend());
        if(vr[i].size() > 0) 
            sort(vr[i].begin(), vr[i].end());
    }
    for(int i = 1; i <= n; i++) 
    {
        for(auto j : vr[i]) 
        {
            if(j.second.second == 1) 
            {
                sum -= bit1.range_sum(j.first + 1, q) * j.second.first;
                bit.add(j.first, -j.second.first);
            } 
            else 
            {
                sum -= bit.range_sum(1, j.first - 1);
                bit1.add(j.first, -1);
            }
        }
        for(auto j : vl[i]) 
        {
            if(j.second.second == 1) 
            {
                sum += bit1.range_sum(j.first + 1, q) * j.second.first;
                bit.add(j.first, j.second.first);
            } 
            else 
            {
                sum += bit.range_sum(1, j.first - 1);
                bit1.add(j.first, 1);
            }
        }
        arr[i] = sum + a[i] * bit1.range_sum(1, q);
    }
    for(int i = 1; i <= n; i++) 
        cout << arr[i] << ' ';
    cout << "\n";
    return 0;  
}
