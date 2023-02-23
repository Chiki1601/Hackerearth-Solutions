#include <bits/stdc++.h>
using namespace std;
 
int main()
{
   	int n;
   	cin >> n;
   	assert(2 <= n and n <= 1000);
   	for(int i = 1 ; i <= n ; i++)
   	{
    	int value;
    	cin >> value;
    	assert(1 <= value and value <= 10000);
   	}
   	for(int i = 1 ; i <= n - 1 ; i++)
    	cout <<  i << " " << (i + 1) << endl;
}
