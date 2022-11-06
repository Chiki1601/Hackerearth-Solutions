#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
	{
        int a, b, n = 0;
		cin >> a >> b;
        for(int i = a; i <= b; i++)
		{
            int c = i, sum = 0;
            while(c > 0)
			{
                int x = c % 10;
                sum = 10 * sum + x;
                c /= 10;
            }
            if(i == sum)
                n++;
        }
        cout << n << endl;
    }
    return 0;
}
