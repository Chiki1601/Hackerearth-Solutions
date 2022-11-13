#include <bits/stdc++.h>
using namespace std;
char str[10];
 
int convert(char str[])
{
	int x, y, ret; 
	x = (str[0] - '0') * 10 + (str[1] - '0');
	y = (str[3] - '0') * 10 + (str[4] - '0');
	return x * 60 + y;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, i, j, n, x, tc, lim, begin, travel, choose, wake, start, end, ans, req, beg, takes, last;
	tc = 1;
	cin >> t;
	while (t--) 
	{
		cout << "Case " << tc++ << ": ";
		cin >> n;
		cin >> str; 
		lim = convert(str);
		cin >> str; 
		wake = convert(str);
		cin >> str; 
		beg = convert(str);
		cin >> travel >> choose;
		begin = max(wake, beg - travel);
		req = travel * 2 + choose;
		ans = -1;
		last = 1000000007;
		for (i = 0; i < n; ++i) 
		{
			cin >> str; 
			start = convert(str);
			cin >> str; 
			end = convert(str);
			if (begin+req < start && begin+req < lim) 
			{
				if (ans == -1 || begin+req < last) 
				{
					ans = i + 1;
					last = begin + req;
				}
			} 
			else if (max(end, begin) + req < lim) 
			{
				takes = max(end, begin) + req;
				if (takes < last) 
				{
					last = takes;
					ans = i + 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
