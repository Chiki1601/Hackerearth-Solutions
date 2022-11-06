#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, r, g, b, i;
    cin >> t >> r >> g >> b;
    int cr = 0, cb = 0, cg = 0, cc = 0, cy = 0, cm = 0, cw = 0, cB = 0;
    for(i = 0; i < t; i++)
    {
        int j = i / r, k = i / g, l = i / b;
        if(j % 2 == 1 && k % 2 == 0 && l % 2 == 0)
        cr++;
        if(j % 2 == 0 && k % 2 == 1 && l % 2 == 0)
        cg++;
        if(j % 2 == 0 && k % 2 == 0 && l % 2 == 1)
        cb++;
        if(j % 2 == 1 && k % 2 == 1 && l % 2 == 0)
        cy++;
        if(j % 2 == 0 && k % 2 == 1 && l % 2 == 1)
        cc++;
        if(j % 2 == 1 && k % 2 == 0 && l % 2 == 1)
        cm++;
        if(j % 2 == 1 && k % 2 == 1 && l % 2 == 1)
        cw++;
        if(j % 2 == 0 && k % 2 == 0 && l % 2 == 0)
        cB++; 
    }
    cout << cr << " " << cg << " " << cb << " " << cy << " " << cc << " " << cm << " " << cw << " " << cB;
}
