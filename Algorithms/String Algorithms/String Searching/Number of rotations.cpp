#include<bits/stdc++.h>
using namespace std;
string a, b;
long long n, l[20055], r[20055], mm[20055], ans = INT_MAX;
vector<pair<long long, long long>> t;
 
long long compa(long long x) 
{
    x %= n;
    if(x < 0) 
        x += n;
    return x;
}
void foo(long long l, long long r, long long s, long long m) 
{
    ans = min(ans, m + 2 * l + (r < s ? s : (2 * r - s)));
    s = compa(n - s); 
    swap(l, r);
    ans = min(ans, m + 2 * l + (r < s ? s : (2 * r - s)));
}
 
void zoo(long long s) 
{
    memset(mm, 0, sizeof mm);
    long long rsh = 0, m = 0;
    for(long long i = 0; i < n; i++) 
    {
        if(a[compa(i + s)] != b[i]) 
        {
            mm[i] = 1; 
            m++;
        }
    }
    for(auto i : t) 
    {
        if(!mm[i.second]) 
            continue;
        foo(i.first, rsh, s, m);
        rsh = max(rsh, r[i.second]);
    }
    foo(0, rsh, s, m);
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long k;
    cin >> k;
    cin >> a >> b;
    n = a.size();
    if(count(b.begin(), b.end(), '1')==0) 
        return cout << (count(a.begin(), a.end(), '1') == 0 ? 0 : -1), 0;
    for(long long i = 0; i < n; i++) 
    {
        while(b[compa(i - l[i])] == '0') 
            l[i]++;
        while(b[compa(i + r[i])] == '0') 
            r[i]++;
        t.push_back({l[i], i});
    }
    sort(t.rbegin(), t.rend());
    for(long long i = 0; i < n; i++) 
        zoo(i);
    cout << ans * k;
}
