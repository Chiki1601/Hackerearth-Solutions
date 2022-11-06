#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
	int t, n, a, b;
	cin >> t;
	string s;
	while(t--) 
	{
		cin >> n >> a >> b >> s;
		map<char, int> need({{'0', a}, {'1', b}, {'2', n - a - b}});
		for(auto c : s)
			--need[c];
		int ans = 0;
		for(auto &c : s)
			if(need[c] < 0)
				for(char nc = '0'; nc < c; ++nc)
					if(need[nc] > 0) 
					{
						++need[c];
						--need[nc];
						c = nc;
						++ans;
						break;
					}
		reverse(s.begin(), s.end());
		for(auto &c : s)
			if(need[c] < 0)
				for(char nc = '2'; nc > c; --nc)
					if(need[nc] > 0) 
					{
						++need[c];
						--need[nc];
						c = nc;
						++ans;
						break;
					}
		reverse(s.begin(), s.end());
		cout << ans << "\n" << s << "\n";
	}
}
