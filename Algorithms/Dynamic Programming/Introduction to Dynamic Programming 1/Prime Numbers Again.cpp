#include<bits/stdc++.h>
using namespace std;
int prime[10001];
 
int main()
{
	for(int i = 0; i < 10001; i++)
	    prime[i] = 1;
	for(int i = 2; i * i <= 10000; i++)
    {
        if(prime[i] == 1)
        {
            for(int j = i * i; j <= 10000; j += i)
                prime[j] = 0;
        }
    }
	prime[4] = prime[27] = prime[3125] = 1;
	prime[0] = prime[1] = 0;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(prime[n] == 1)
		    cout << 1 << endl;
		else if(n % 2 == 0 || prime[n - 2] == 1 ||  prime[n - 4] == 1 || prime[n - 27] == 1)
		    cout << 2 << endl;
		else if(prime[n - 3125] == 1)
		    cout << 2 << endl;
		else
		    cout << 3 << endl;		
	}
}
