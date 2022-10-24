#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, count = 0;
	cin >> n;
	string s, t, tmp;
	cin >> s >> t;
	for(int i = 0; i < n; i++)
	{
		tmp = s.substr(i);
		if(t.find(tmp) == 0)
		{
			cout << count << endl;
			return 0;
		}
		count++;
	}
}
