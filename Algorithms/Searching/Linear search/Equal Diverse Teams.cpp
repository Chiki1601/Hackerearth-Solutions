#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, n, k, x, b[1000005];
	cin >> T;
	while(T--)
    {
		int tot = 0, tot1 = 0;
		for(int i = 1; i <= n; i++) 
            b[i] = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
        {
			cin >> x;
			if(!b[x]) 
                tot++;
			if(b[x] == 1) 
                tot1++;
			b[x]++;
		}
		tot -= tot1;
		if(tot1 + tot <= 2 * k && tot1 * 2 + tot >= 2 * k)  
            puts("YES");
		else 
            puts("NO");
	}
	return 0;
}
