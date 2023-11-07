#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int lo = 1, hi = n, c = 1;
    while(lo <= hi) 
    {
        int mid = (lo + hi) / 2, ind = 0, l = 0;
        while(ind < n) 
        {
            if(s[ind] == '0') 
                ind += 1;
            else 
            {
                l += 1;
                ind += mid;
            }
        }
        if(l <= k) 
        {
            c = mid;
            hi = mid - 1;
        } 
        else 
            lo = mid + 1;
    }
    cout << c << "\n";
    return 0;  
}
