#include <bits/stdc++.h>
using namespace std;
multiset<string> se;
multiset<string> :: iterator it;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, k;
	cin >> n;
	string s;
	for(i = 0; i < n; ++i) 
	{
	    cin >> s;
	    k = 0;
	    for(it = se.begin(); it != se.end(); ++it) 
	        k += (*it < s);
        cout << k << "\n";
	    se.insert(s);
	}
	return 0;
}
