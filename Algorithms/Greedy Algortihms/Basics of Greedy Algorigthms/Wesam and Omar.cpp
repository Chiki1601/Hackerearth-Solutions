#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
    cin >> t;
	while(t--)
    {
		string s[3];
		for(int i = 0; i < 3; i++)
			cin >> s[i];
		if(s[1][1] == '.') 
            cout << "YES" << endl;
		else if(s[0][1] == '.' && s[1][2] == '.') 
            cout << "YES" << endl;
		else if(s[1][0] == '.' && s[2][1] == '.') 
            cout << "YES" << endl;
		else 
            cout << "NO" << endl;
	}
	return 0;
}
