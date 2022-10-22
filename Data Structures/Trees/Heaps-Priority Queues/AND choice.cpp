#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	while(t--) 
	{
		int n, x = 0;
		cin >> n;
		vector<int>a(n);
		for(int i = 0; i < n; i++) 
			cin >> a[i];
		for(int i = 31; i >= 0; i--) 
		{
			int cnt = 0;
			for(int j = 0; j < n; j++) 
			{
				if((a[j] & (x | 1 << i)) == (x | (1 << i)))
					cnt++;
			}
			if(cnt >= 2)
				x |= 1 << i;
		}
		cout << x << endl;
	}
	return 0;
}
