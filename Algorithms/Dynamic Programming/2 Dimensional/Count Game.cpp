#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 1; 
    cin >> n;
	vector<int> b;
	for(int i = 0, ThxDem = n; i < ThxDem; ++i)
    {
		int x; 
        cin >> x;
		for(auto y : b) 
            x = min(x, x ^ y);
		if(x) 
            b.push_back(x);
	}
    for(int i = 0, ThxDem = n - b.size(); i < ThxDem; ++i)
        ans = 2 * ans % 1000000007;
	cout << ans << endl;
}
