#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int k, ans = 0;
	string s;
	cin >> k >> s;
	for(int i = 0; i < s.size(); i++)
	{
		int count = 0;
		set<char> ch;
		for(int j = i; j < s.size(); j++)
		{
			ch.insert(s[j]);
			if(ch.size() == k)
				ans++;
		}
		ch.clear();
	}
	cout << ans << endl;
}
