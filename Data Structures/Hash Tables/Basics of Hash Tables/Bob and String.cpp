#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s, t;
		cin >> s >> t;
		int f[26] = {0}, f1[26] = {0}, count = 0;
		for(char ch : s)
			f[ch - 97]++;
		for(char ch : t)
			f1[ch - 97]++;
		for(int i = 0; i < 26; i++)
			count += abs(f[i] - f1[i]);
		cout << count << endl;
	}
}
