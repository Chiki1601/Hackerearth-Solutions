#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, max = 0; 
	cin >> n;
	string s, ans = ""; 
	cin >> s;
	for(int i = 'z'; i >= 'a'; --i)
	{
		for(int j = max; j < n; ++j)
		{
			if(s[j] == i)
			{
				ans.push_back(s[j]);
				max = j;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
