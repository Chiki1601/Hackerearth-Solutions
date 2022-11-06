#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	string str;
	int t1, t2, i, j, count = 0;
	cin >> str >> t1;
	while(t1--)
	{
		int ind;
		char ch;
		cin >> ind >> ch;
		str[ind - 1] = ch;
	}
	cout << str << endl;
	cin >> t2;
	string rev = str;
	while(t2--)
	{
		int start, end;
		cin >> start >> end;
		reverse(str.begin() + start - 1, str.begin() + end);
	}
	cout << str << endl;
	for(i = 0; i < str.length(); i++)
	{
		if(str[i] == rev[i])
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
