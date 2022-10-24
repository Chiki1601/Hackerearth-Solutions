#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int i, n, m, num;
    cin >> num;
    for(i = 0; i < num; i++)
    {
        cin >> n >> m;
        if(n % 2 == 0 && m <= n / 2 || m == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }                           
}
