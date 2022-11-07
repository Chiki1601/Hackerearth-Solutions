#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long tc; 
	cin >> tc; 
	while(tc--)
	{
		long long n, m; 
		cin >> m >> n;
		long long a[n], dp[m + 1] = {0}; 
		for(long long i = 0; i < n; i++) 
			cin >> a[i];
		for(long long i = 0; i < m + 1; i++)
		{
			if(dp[i] == 0)
			{
				for(long long j = 0; j < n; j++) 
				{
					if(i + a[j] <= m) 
						dp[i + a[j]] = 1;
					else 
						break;
				}
			}
		}
		if(dp[m] == 1) 
			cout << "Little Deepu";
		else 
			cout << "Kate";
		cout << endl;
	}
}
