#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        int x = n % 4;
        if(x == 0)
            cout << "1" << " " << n << endl;
        else if(x == 1)
            cout << "1" << " " << "1" << endl;
        else if(x == 2)
            cout << "2" << " " << n << " 1" << endl;
        else
            cout << "0" << endl;
    }
}
