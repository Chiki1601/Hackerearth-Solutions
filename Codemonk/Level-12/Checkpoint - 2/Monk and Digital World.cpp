#include <bits/stdc++.h>
using namespace std;
int m1[30], m2[30];

int main()
{
	int n, i, j;
	char str[1000001];
	cin >> n >> str;
	for(i = 0; str[i]; ++i) 
	    m1[str[i] - 'a']++;
	cin >> str;
	for(i = 0; str[i]; ++i) 
	    m2[str[i] - 'a']++;
	for(i = 0; i < 26; ++i) 
	{
	    if(m1[i] != m2[i]) 
	    {
	        cout << "NO" << endl; 
		    return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
