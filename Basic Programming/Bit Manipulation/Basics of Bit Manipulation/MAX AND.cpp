#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T, n;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++) 
            cin >> b[i];
        int ans = (1LL << 32) - 1;
        for(int i = 0; i < n; i++) 
        {
            ans = ans & a[i];
            ans = ans & b[i];
        }
        cout << ans << "\n";
    }
    return 0;  
}
