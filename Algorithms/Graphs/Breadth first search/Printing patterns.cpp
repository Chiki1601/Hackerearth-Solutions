#include <bits/stdc++.h> 
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int r, c, ci, cj, i, j;
	cin >> r >> c >> ci >> cj;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			cout << max(abs(i - ci), abs(j-cj)) << " ";
		cout << endl;
	}
	return 0;
}
