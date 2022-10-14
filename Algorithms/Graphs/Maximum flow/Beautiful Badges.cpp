#include <bits/stdc++.h>
using namespace std;
 
bool check(int a, int b)
{
    if(a > b) 
        swap(a, b);
    a *= a;
    a *= 2;
    double tmp = sqrt(a);
    return tmp > b;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, n, l = 0, r = 0, res = 0;
    cin >> n;
    vector<int> f, s;
    for(int i = 0; i < n; i++) 
    {
        cin >> a >> b;
        if(a == 1) 
            f.push_back(b);
        else 
            s.push_back(b);
    }
    sort(f.begin(), f.end());
    sort(s.begin(), s.end());
    for(; l < f.size() && r < s.size();) 
    {
        if(check(f[l], s[r])) 
        {
            res++;
            l++;
            r++;
        }
        else if(f[l] < s[r]) 
            l++;
        else 
            r++;
    }
    cout << res;
}
