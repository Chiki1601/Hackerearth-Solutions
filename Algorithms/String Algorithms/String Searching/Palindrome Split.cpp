#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
		string s;
		cin >> s;
		vector<int> v(26, 0);
		for(auto i : s) 
			v[i - 'a'] += 1;
		int c = 0;
		for(auto i : v) 
			c += (i / 2);
		cout << c << endl;
	}
	return 0;  
}
