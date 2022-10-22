#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, q, a;
	cin >> n >> m;
	vector<vector<vector<int>>> pref(30, vector<vector<int>> (n + 1, vector<int> (m + 1, 0)));
	for(int r = 0; r < n; ++r)
    {
		for(int c = 0; c < m; ++c)
        {
			cin >> a;
			for(int bit = 0; bit < 30; ++bit)
            {
				pref[bit][r + 1][c + 1] = pref[bit][r + 1][c] + pref[bit][r][c + 1] - pref[bit][r][c] + (a & 1);
				a >>= 1;
			}
		}
	}
	cin >> q;
	while(q--)
    {
		int r1, c1, r2, c2, ans = 0;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; 
		c1--;
		for(int bit = 0; bit < 30; ++bit)
        {
			if(pref[bit][r2][c2] - pref[bit][r2][c1] - pref[bit][r1][c2] + pref[bit][r1][c1] > 0)
				ans |= 1 << bit;
		}
		cout << ans << "\n";
	}	
    return 0;
}
