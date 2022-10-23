#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; 
	cin >> t; 
	while(t--)
	{
		long long count = 0, l , r; 
		cin >> l >> r;
		for(long long i = 1; i * i <= r; ++i )
		{
			long long x =  max ((long long)ceil((double)(l - i * i) / (2 * i)  + 1 ), (long long)1);
			long long y = (long long)floor((double)(r - i * i) / (2 * i) + 1 );
			if(y > 0)
				count += y - x + 1; 
		}
		cout << count << endl; 
	}
	return 0;
}
