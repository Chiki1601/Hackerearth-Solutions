#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while(t--) 
	{
        cin >> n;
        int a[n], b[n], mx = 1;
        for(int i = 0; i < n; ++i) 
		{
            cin >> a[i];
            mx = (long long) mx * (a[i] + 1) % 1000000007;
        }
        for(int i = 0; i < n; ++i) 
		{
            cin >> b[i];
            mx = (long long) mx * (b[i] + 1) % 1000000007;
        }
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        int mn = 1;
        for (int i = 0; i < n; ++i)
            mn = (long long) mn * (a[i] + b[i] + 1) % 1000000007;
        cout << mn << ' ' << mx << endl;
    }
}
