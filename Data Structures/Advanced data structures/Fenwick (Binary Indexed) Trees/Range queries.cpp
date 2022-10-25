#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, q, a, l, r, x, f = 0;
	cin >> t;
	vector<int> p(100007, 0), ans(100007, 0);
    for(int i = 1; i <= 100000; i++) 
    {
        f ^= i;
        ans[i] = ans[i - 1] ^ f;
    }
	while(t--) 
    {
		cin >> n >> q;
		for(int i = 1; i <= n; i++) 
        {
            cin >> a;
			p[a] = i;
		}
		while(q--) 
        {
			cin >> l >> r;
			x = 0;
			do 
            {
				x++;
			} 
            while(l <= p[x] && p[x] <= r);
			    cout << ans[x - 1] << " ";
		}	
        cout << endl;
	}
	return 0;
}
