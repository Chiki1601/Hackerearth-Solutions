#include <bits/stdc++.h>
using namespace std; 
long long n, t, i, j, sol, h, a[1005], b[1005];
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for(i = 1; i <= t; i++)
	{
		cin >> n;
		for(j = 1; j <= n; j++)
			cin >> a[j];
		sol = 0;
		for(j = 1; j <= n; j++)
		    b[j] = -2000000000000000000;
		for(j = 1; j <= n; j++)
		{
			for(h = j - 1; h >= 1; h--)
			    if(b[h + 1] < b[h] + (h + 1) * a[j]) 
                    b[h + 1] = b[h] + (h + 1) * a[j];
			if(b[1] < a[j]) 
                b[1] = a[j];
		}
		for(j = 1; j <= n; j++)
		    if(b[j] > sol) 
                sol = b[j];
		cout << sol << "\n";
	}
}
