#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int t, n, arr[101] = {0};
 	cin >> t >> n;
    while(n--)
    {
        long long int x, f = 0;
		cin >> x;
        long long int val = min(x, t);
        for(int i = val; i >= 1; i--)
        {
            if(arr[i] < x)
            {
                arr[i] = x;
                cout << "YES" << endl;
                f = 1;
                break;
            }
        }
        if(!f)
        	cout << "NO" << endl;
     }
 }
