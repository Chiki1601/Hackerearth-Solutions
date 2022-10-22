#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        if(n == 0 || (n & (n - 1)) == 0)  
           	cout << "0" << endl;
        else
            cout << "1" << endl;
    }
 	return 0;
}
