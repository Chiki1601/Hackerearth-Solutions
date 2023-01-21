#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> H(n);
	for(int& h : H) 
        cin >> h;
	vector<vector<int>> minDp(n, vector<int>(n + 1, 1000000000));
	for(int h = 0; h <= n; ++h) 
        minDp[n - 1][h] = 0;
	for(int a = n - 2; a >= 0; --a) 
    {
		for(int b = a + 1; b <= min(n - 1, a + k); ++b) 
        {
			int diff = abs(H[a] - H[b]);
			int dp = minDp[b][diff] + 1;
			minDp[a][diff] = min(minDp[a][diff], dp);
		}
		for(int h = 1; h <= n; ++h)
			minDp[a][h] = min(minDp[a][h], minDp[a][h - 1]);
	}
	if(minDp[0][n] >= 1000000000) 
        cout << "-1" << endl;
	else    
        cout << minDp[0][n] << endl;
}
