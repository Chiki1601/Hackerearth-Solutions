#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t;
	cin >> t;
	while(t--)
	{
	    string s;
		cin >> s;
		long long i = 0, j = 0, a = 0, b = 0, c = 0, ans = (s.length() + 1) * (s.length()) / 2;
		for(long long i = 0; i < s.length(); i++)
		{
			if(s[i] == 'a')
			{
				a = i + 1;
				ans -= min(b, c);
			}
			if(s[i] == 'b')
			{
				b = i + 1;
				ans -= min(a, c);
			}
			if(s[i] == 'c')
			{
				c = i + 1;
				ans -= min(b, a);
			}
		}
		cout << ans << endl;
	}
}
