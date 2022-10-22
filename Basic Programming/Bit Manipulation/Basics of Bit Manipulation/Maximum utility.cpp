#include<bits/stdc++.h>
using namespace std;
int n, k, a[200005], b[200005];
 
long long func(int x)
{
    long long res = 0;
    for(int i = 1; i <= n; i++) 
		if((x|a[i]) == x) 
			res += b[i];
    return res;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++) 
			cin >> a[i];
		for(int i = 1; i <= n; i++) 
			cin >> b[i];
		long long ans = func(k), p = 0;
		for(int i = 30; i >= 0; i--)
		{
			int b = (1<<i);
			if(k & b) 
			{
				ans = max(ans, func(p + b - 1));
				p += b;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
