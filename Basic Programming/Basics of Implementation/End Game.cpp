#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    unsigned int t;
    cin >> t;
    while(t--)
    {    
        long long n, a, b, c, d, move; 
        cin >> n >> a >> b >> c >> d >> move;
        long long x = n - a + move, y = n - c, z = abs(b - d);
        (x >= y && z <= x) ? cout << "Draw" << endl : cout << "White Wins" << endl;
   }
}
