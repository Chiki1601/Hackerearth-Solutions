#include <bits/stdc++.h>
using namespace std;
long long n, m, l[1000], x, tests;
string st[1000];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> tests;
	for(; tests; --tests)
	{
 		cin >> n >> m;
 		for (int i = 1; i <= n; i++)
 			cin >> st[i];
 		for (int i = 1;i <= n; i++)
 			l[i] = l[i - 1] * 2 + st[i].size();
 		for(; m; --m)
 		{
 			cin >> x;
 			for(int i = n; i; --i)
 			{
 				if(x >= 2 * l[i - 1])
 				{
 					cout << st[i][x - 2 * l[i - 1]];
 					break;
 				}
 				else if(x >= l[i - 1])
 					x = 2 * l[i - 1] - x - 1;
 			}
 		}
 		cout << endl; 
	}
 	return 0;
}
