#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x, xorr = 0, q;
	cin >> n;
	vector<int> cnt(201);
    for(int i = 0; i < n; ++i)
    {
		cin >> x;
		cnt[x]++;
		xorr ^= x;
	}
	map<int, int> cur = {{0, 0}};
	for(int a = 1; a < 201; ++a)
    {
		if(!cnt[a])
			continue;
		auto prev = cur;
		for(auto e: prev)
        {
			x = e.first ^ a;
			if(cur.count(x))
				cur[x] = min(cur[x], e.second + 1);
			else
				cur[x] = e.second + 1;
		}
	}
	cin >> q;
	while(q--)
    {
		cin >> x;
		x ^= xorr;
		cout << (cur.count(x) ? cur[x] : -1) << "\n";
	}
	return 0;
}
