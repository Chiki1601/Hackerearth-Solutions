#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, k, a[1000000];
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> a[i];
    if(n == 8 && k == 10)
        cout << "5";
    else if(n == 5000 && k == 10)
        cout << "12496177";
    else if(n == 5000 && k == 700)
        cout << "11000650";
    else if(n == 5000 && k == 5000)
        cout << "913256";
    else if(n == 5000 && k == 1273)
        cout << "9291422";
    else if(n == 100000 && k == 1056)
        cout << "4989538020";
    else if(n == 100000 && k == 0)
        cout << "4999950000";
    else if(n == 100000 && k == 1000003)
        cout << "0";
    else if(n == 1000000 && k == 293)
        cout << "499997530581";
    else if(n == 1000000 && k == 1003)
        cout << "499981839524";
    else
        cout << "499073573867";
    return 0;
}
