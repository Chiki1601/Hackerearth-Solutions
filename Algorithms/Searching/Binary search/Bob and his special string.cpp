#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n, a[26] = {0}, ans = INT_MAX;
	cin >> n;
	string s;
	cin >> s;
   	for(long long int i = 0; i < (int)s.size(); i++)
	   	a[s[i] - 'a']++;
   	for(long long int i = 1; i < n + 1; i++)
	{
       	int c = 0;
       	for(long long int j = 0; j < 26; j++)
		   	c += (a[j] + i- 1 ) / i;
       	if(c <= n) 
		{
			cout << i << endl;
			break;
		}
   	}
    return 0;
}
