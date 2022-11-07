#include <bits/stdc++.h>
using namespace std;
int tyms[102][102][102], freq[102][102], val[3];
map <string,int> m;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q, x1, y1, x2, y2, tot;
	string type;
	m["R"] = 0, m["G"] = 1, m["B"] = 2;
	cin >> n >> q;
	assert(n >= 1 && n <= 100);
	assert(q >= 1 && q <= 500000);
	for(int i = 1; i <= n; i++) 
	{
		for(int j = 1; j <= n; j++) 
			cin >> freq[i][j], assert(freq[i][j] >= 1 && freq[i][j] <= 100);
	}
	for(int i = 1; i <= n; i++) 
	{
		for(int j = 1; j <= n; j++) 
		{
			for(int k = 1; k <= 100; k++) 
			{
				tyms[i][j][k] = tyms[i - 1][j][k] + tyms[i][j - 1][k] - tyms[i - 1][j - 1][k];
				tyms[i][j][k] += (freq[i][j] == k);
			}
		}
	}		
	while(q--) 
	{
		cin >> tot >> x1 >> y1 >> x2 >> y2 >> type;
		assert(tot <= 100);
		assert(x1 >= 1 && x1 <= n);
		assert(x2 >= 1 && x2 <= n);
		assert(y1 >= 1 && y1 <= n);
		assert(y2 >= 1 && y2 <= n);
		assert(x2 >= x1 && y2 >= y1);
		for(int i = 0; i < 3; i++) 
			val[i] = 0;
		for(int i = 1; i <= 100; i++) 
		{
			int x = tyms[x2][y2][i] - tyms[x1 - 1][y2][i] - tyms[x2][y1 - 1][i] + tyms[x1 - 1][y1 - 1][i];
			val[(tot / i) % 3] += x;
		}
		cout << val[m[type]] << endl;
	}
	return 0;
}
