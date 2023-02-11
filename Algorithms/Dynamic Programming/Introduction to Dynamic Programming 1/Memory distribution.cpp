#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a, b, c, i, f[10010];
	cin >> n >> a >> b >> c;
	for(i = 1; i <= n; i++)
	{
		f[i] =- 10000;
		if(i >= a) 
            f[i] = f[i - a] + 1;
		if((i >= b) && (f[i - b] + 1 > f[i])) 
            f[i] = f[i - b] + 1;
		if((i >= c) && (f[i - c] + 1 > f[i])) 
            f[i] = f[i - c] + 1;
	}
	cout << f[n] << endl;
	return 0;
}
