#include <bits/stdc++.h>
using namespace std;
 
int findDates(int d, int m, int y)
{
    int until = y / 100 - 1;
    long long int total = (until + 1) * 11;
    if(y % 100 >= 4) 
        total += min((y % 100 - 3), 11);
    if(y % 100 <= 13 && y % 100 >= 3)
    {
        int dc, mc, yc;
        yc = y;
        mc = y % 100 - 1;
        dc = m - 1;
        if(m - mc > 0 || (m == mc && d - dc >= 0)) 
            return total + 1;
    }
    if(total <= 0) 
        return 0;
    return total;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int d1, m1, y1, d2, m2, y2;
        scanf("%d:%d:%d %d:%d:%d", &d1, &m1, &y1, &d2, &m2, &y2);
        if(d1 + 1 == m1 && m1 + 1 == y1 % 100) 
            cout << findDates(d2, m2, y2) - findDates(d1, m1, y1) +1 << endl;
        else 
            cout << findDates(d2, m2, y2) - findDates(d1, m1, y1) << endl;
    }
    return 0;
}
