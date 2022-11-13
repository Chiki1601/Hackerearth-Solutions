#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int test, n, moveX[256], moveY[256], x, y, res;
    char s[200001];
    moveX['L'] = -1;
    moveX['R'] = 1;
    moveY['D'] = -1;
    moveY['U'] = 1;
    cin >> test;
    while(test--) 
    {
        cin >> s;
        n = strlen(s);
        x = y = 0;
        for(int i = 0; i < n; ++i) 
        {
            x += moveX[s[i]];
            y += moveY[s[i]];
        }
        x = abs(x);
        y = abs(y);
        res = (x + 1) / 2 + (y + 1) / 2;
        cout << res << endl;
    }
    return 0;
}
