#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int z;
	for(scanf("%d", &z); z; --z) 
	{
		int n, m, r = -1;
		cin >> n >> m;
		vector<int> v(n);
		for(int i = 0; i < n; ++i) 
			cin >> v[i];
		--m;
		for(int i = 29; i >= 0; --i) 
		{
			int temp = m >> i;
			if((temp & 1) == 0) 
			{
				temp |= 1;
				int may = 0;
				for(int x : v) 
				{
					if((temp & (x >> i)) == temp) 
						++may;
				}
				if(may) 
					r = max(r, may);
			}
		}
		cout << r << endl;
	}
	return 0;
}
