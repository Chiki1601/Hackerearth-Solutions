#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tests = 1, n;
    cin >> tests;
    for(int _ = 0; _ < tests; ++_) 
    {
		cin >> n;
		map<int, int64_t> freq;
		int64_t ans = 0;
		for(int i = 1, x; i <= n; ++i) 
		{
			cin >> x;
			int val = x ^ i;
			ans += freq[val];
			++freq[val];
		}
		cout << ans << "\n";
	}
}
