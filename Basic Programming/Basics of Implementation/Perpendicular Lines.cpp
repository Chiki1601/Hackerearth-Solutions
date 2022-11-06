#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
	{
        long long x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(((x1 == x2) && (y1 == y2)) || ((x3 == x4) && (y3 == y4)))
            cout << "INVALID" << endl;
        else if(((x2 - x1) * (x4 - x3)) == (-(y2 - y1) * (y4 - y3)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
