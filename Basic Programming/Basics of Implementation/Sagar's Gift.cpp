#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  	string s = "", arr;
  	int i, j, n, t;
  	cin >> t;
  	for(i = 0; i < t; i++)
  	{
    	cin >> n;
    	for(j = 0; j < n; j++)
    	{
      		cin >> arr;
      		s += arr;
    	}
    	sort(s.begin(), s.end());
    	j = s.size() - 1;
    	while(j >= 0)
    	{
      		cout << s[j];
      		j--;
    	}
    	s = "";
    	cout << endl;
   	}
}
