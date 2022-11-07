#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	for(cin >> t; t--;)
	{
		long long int n, a = 0, b, x = 0, y = 0, z = 0;
		cin >> n;
		string s;
		while(n--)
		{
			cin >> s;
			a = 0, b = 0;
			a = count(s.begin(), s.end(), '1');
			b = count(s.begin(), s.end(), '0');
			if(a > 0)
				x++;
			if(b > 0)
				y++;
			if(a > 0 and b > 0)
				z++;
		}
		cout << ((x * (x - 1)) / 2 + (y * (y - 1)) / 2) - (z * (z - 1)) / 2 <<endl;
	}
}
