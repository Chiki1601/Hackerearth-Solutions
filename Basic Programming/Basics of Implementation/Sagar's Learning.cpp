#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    unsigned long a,k;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
      	cin >> a;
        k = a / 3;
        if(a < 3)
        	cout << "-1" << endl;
        else
        	cout << k << " " << 2 * k << " " << 3 * k << endl;
    }
    return 0;
}
