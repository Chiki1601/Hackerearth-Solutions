#include <bits/stdc++.h>
using namespace std;
int spf[100010];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 2, ThxDem = 100010; i < ThxDem; ++i)
		if(!spf[i]) 
			for(int j = i; j < 100010; j += i) 
				if(!spf[j])
					spf[j] = i;
	int t; 
	cin >> t;
	while(t--)
	{
		long long am1 = 0, amp = 0;
		int n; 
		cin >> n;
		for(int i = 0, ThxDem = n; i < ThxDem; ++i)
		{
			int x; 
			cin >> x;
			am1 += x==1;
			amp += spf[x]==x;
		}
		cout << amp * (am1 * (am1 - 1) / 2) << "\n";
	}
}
