#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n, max, len_upto[10] = {0};
	cin >> n;
	for(int z = 0; z < n; z++)
	{
		long long int a;
		cin >> a;
		int digits[10] = {0};
		while(a != 0)
		{
			int x = a % 10;
			digits[x] = 1;
			a /= 10;
		}
		max = 1;
		for(int i = 0; i < 10; i++)
		{
			if(digits[i] == 1 && len_upto[i] >= max)
				max = len_upto[i] + 1;
		}
		for(int i = 0; i < 10; i++)
		{
			if(digits[i] == 1)
			  len_upto[i] = max;
		}
	}
	int ans = 0;
	for(int i = 0; i < 10; i++)
	{
		if(len_upto[i] > ans)
			ans = len_upto[i];
	}
	cout << ans << endl;
}
