#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testcase;
	for(cin >> testcase; testcase > 0; testcase--)
	{
		int n, ret = 0;
		cin >> n;
		n += 2;
		vector<vector<int>> a(n,vector<int>(n));
		for(int i = 1; i < n - 1; ++i) 
			for(int j = 1; j < n - 1; ++j)
				cin >> a[i][j];
		vector<vector<int>> f(n, vector<int>(n));
		for(int s = n - 1; s >= 0; s--) 
			for(int t = s + 1; t < n; ++t)
				if(s + 1 == t)
					f[s][t] = 1;
				else
				{
					for(int m = s + 1; m < t; ++m)
						if((a[s][m] || a[t][m]) && f[s][m] && f[m][t])
						{
							f[s][t] = 1;
							break;
						}
				}
		for(int i = 1; i < n - 1; ++i)
			if(f[0][i] && f[i][n - 1]) 
				++ret;
		cout << ret << endl;
	}
	return 0;
}
