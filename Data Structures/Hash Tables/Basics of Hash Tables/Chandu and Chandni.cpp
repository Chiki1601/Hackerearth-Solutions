#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int v[2000000], T;
	double fi =((double)((1 + sqrt(5)) / 2.0));
	for(int i = 1; i <= 1000000; i++)
        v[i] = -1;
    for(int i = 1; i <= 1000000; i++)
        v[(int)(fi * (double)i)] = (int)(fi * fi * i);
    cin >> T;
    while(T--)
	{
        int a, b;
        cin >> a >> b;
        if(v[a] == b)
            cout << "Chandu" << endl;
        else
            cout << "Chandni" << endl;
     }
}
