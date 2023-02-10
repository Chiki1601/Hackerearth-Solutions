#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, n, x, y;
    cin >> n;
    x = (n + 1) / 2;
    y = n - x;
    long long int a [x], b [y], xr, t;
    for(i = 0; i < x; i++) 
        cin >> a [i];
    for(i = 0; i < y; i++) 
        cin >> b [i];
    vector <long long int> c {0};
    unordered_map <int, long long int> d = {{0, 1}};
    for(auto x : a) 
    {
        for(i = c.size () - 1; i >= 0; i--) 
        {
            xr = x ^ c [i];
            c.push_back (xr);
            d [xr]++; 
        }
    }
    c = {0};
    t = d [0];
    for(auto x : b) 
    {
        for(i = c.size () - 1; i >= 0; i--) 
        {
            xr = x ^ c [i];
            c.push_back (xr);
            t += (d.find (xr) != d.end ()) ? d [xr] : 0;
        }
    }
    cout << t - 1 << endl;
    return 0;
}
