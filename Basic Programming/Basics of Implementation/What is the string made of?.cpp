#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    string s;
    int sum = 0;
    cin >> s;
    int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for(int i = 0; i < s.size(); i++)
        sum += a[(s[i] - '0')];
    cout << sum;
}
