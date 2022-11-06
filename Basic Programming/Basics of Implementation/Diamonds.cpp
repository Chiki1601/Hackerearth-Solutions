#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int T;
	cin >> T;
	for(int z = 0; z < T; z++)
	{
		int n, m;
		cin >> n >> m;
		string s[n];
		cin.ignore();
		for(int i = 0; i < n; i++)
		getline(cin,s[i]);
		int ans=0;
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = 0; j < 2 * (m - 1); j++)
			{
				if(s[i][j] == '/' && s[i][j + 2] == '\\' && s[i + 1][j] == '\\' && s[i + 1][j + 2] == '/')
					ans++;
			}
		}
		cout << ans << endl;
	}
}
