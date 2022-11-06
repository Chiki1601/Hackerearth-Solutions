#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    int i, j;
    cin >> s;
    if (s == "ELEMENT")
    {
        cin >> i >> j;
        cout << j;
    }
    else if (s == "PERMUTATION")
        cout << "13 15 1 6 14 4 5 7 2 16 9 11 10 12 8 3";
    return 0;
}
