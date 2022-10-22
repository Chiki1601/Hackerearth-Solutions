#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m;
	cin >> n >> m;
	set<int> row, col;
	for(int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		row.insert(l);
		col.insert(r);
		cout << (n - row.size()) * 1LL * (n - col.size()) << " ";
	}
	return 0;
}
