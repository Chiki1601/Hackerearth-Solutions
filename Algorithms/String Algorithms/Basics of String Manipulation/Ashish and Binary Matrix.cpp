#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, m;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
    	string s;
    	set<string> st;
		for(int i = 0; i < n; i++)
		{
			cin >> s;
			st.insert(s);
        }
        if(st.size() == n)
			cout << "Yes" << endl;
        else
			cout << "No" << endl;
	}
	return 0;
}
