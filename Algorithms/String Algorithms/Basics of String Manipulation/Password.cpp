#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	string s;
	vector<string> v, vrev;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
		reverse(s.begin(), s.end());
		vrev.push_back(s);
	}
	for(int i = 0; i < n; i++)
		if(find(vrev.begin(), vrev.end(), v[i]) != vrev.end())
		{
			cout << v[i].size() << " " << v[i][v[i].size() / 2];
			break;
		}
}
