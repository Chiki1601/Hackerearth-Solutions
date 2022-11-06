#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int T;
	cin >> T;
	cin.ignore();
 	for(int Z = 0; Z < T; Z++)
	{
		string s;
		getline(cin, s);
		int i = 0, no_strings = 0, char_strings = 0;
		bool b = false;
		while(i < s.size())
		{
			int len = 0;
			bool b1 = false;
			while(s[i] != ' ' && i < s.size())
			{
				if((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A'))
				    b1 = true;
				i++;
				len++;
			}
			if(b1 == true)
			{
				char_strings++;
				no_strings++;
			}
			else
			{
				if(s[i - len] == '0')
				    b = true;
				else
				    no_strings++;
			}
			i++;
		}
 		if(no_strings > 3 || char_strings != 1)
		    b = true;
 		if(b == true)
		    cout << "N" << endl;
		else if(no_strings == 2)
		    cout << "M" << endl;
		else
		    cout << "V" << endl;
 	}
}
