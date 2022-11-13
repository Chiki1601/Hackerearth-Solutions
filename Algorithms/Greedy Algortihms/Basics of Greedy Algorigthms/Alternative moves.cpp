#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, a, b;
    cin >> t;
    while(t--) 
	{
        cin >> n >> a >> b;
        if(a >= n) 
			cout << '1' << "\n";
        else if (a > b) 
			cout << 2 * ((n - b - 1) / (a - b)) + 1 << "\n";
        else 
			cout << "-1"  << "\n";
    }
}
