#include<bits/stdc++.h>
using namespace std;
 
long long int func(long long int x)
{
	long long int items = 1, i;
	for(i = 1; i <= x; i++)
	  	items = 2 * items;
	return items;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int testCases, j;
	cin >> testCases;
 	for(j = 0; j < testCases; j++)
	{
		long long int X, L, N;
		cin >> X >> L >> N;
 		if(N == 0)
			cout << "0" << endl;
		else 
		{
			if(N <= 62)
			{ 
		 		if(X - L / (func(N - 1)) >= 0) 
		  			cout << X - (L / func(N - 1)) << endl;
				else 
					cout << "0" << endl;
			}
			else 
				cout << X << endl;
		}
	}	
	return 0;
}
