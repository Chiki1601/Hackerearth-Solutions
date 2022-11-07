#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.length(), ans = 0, a = 0, max_dif = 0, cur_max = 0;
		bool all_a = true;
		for(int i = 0; i < n; i++)
		{
			int cur = (s[i] == 'A') ? -1 : 1;
			if(cur == -1) 
				a++;
			if(cur == 1) 
				all_a = false;
			cur_max = max(cur, cur_max + cur);
			max_dif = max(max_dif, cur_max);
		}
		cout << ((all_a == true) ? (n - 1) : (a + max_dif)) << endl;
	}
	return 0;
}
