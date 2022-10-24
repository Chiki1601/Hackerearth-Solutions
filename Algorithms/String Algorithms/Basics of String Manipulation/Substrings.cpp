#include <bits/stdc++.h>
using namespace std;
int eq[1000005];
 
int main () 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; 
	cin >> s;
	int cnt = 0, pos = 1;
	long long res = 0;
	for (int i = 1; i <= s.length(); i++) 
	{
		if (i == s.length() || s[i] != s[i - 1]) 
		{
			eq[cnt++] = pos;
			pos = 1;
		} 
		else 
			pos++;
	}
	pos = 0;
	for (int i = 0; i < cnt; i++)
	{
		res += 1LL * eq[i] * (eq[i] + 1) / 2;
		if(eq[i] == 1 && s[pos - 1] == s[pos + 1]) 
			res += min(eq[i - 1], eq[i + 1]);
		pos += eq[i];
	}
	cout << res;
}
