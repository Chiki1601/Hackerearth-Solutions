#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	string st;
	set<long long> ans;
	cin >> st;
	for(int i = 0; i < st.size(); i++)
	{
    	long long s = 0;
    	for(int j = i; j < st.size(); j++)
    	{
        	s = s * 173 + st[j];
        	ans.insert(s);
    	}
	}
	cout << ans.size() << endl;
	return 0;
}
