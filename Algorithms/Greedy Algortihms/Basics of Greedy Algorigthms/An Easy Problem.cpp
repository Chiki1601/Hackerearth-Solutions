#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	  int x;
    auto getTime = []()
    {
		    int h, m, ret = 0;
        cin >> h;
        cin.ignore(1 , ':');
        cin >> m;
		    return m + h * 60;
	  };
	  int l = getTime();
	  cin >> x;
	  for(int i = l; i < 1440; i++)
    {
		    string s;
		    int y = i;
		    for(int j = 0; j < 2; j++, y /= 60)
			      s.push_back('0' + y % 60 % 10), s.push_back('0' + y % 60 / 10);
		    if((accumulate(s.begin(), s.end(), 0) - '0' * 4) % x == 0)
			      return cout << i - l << endl, 0;
	  }
	  cout << "-1" << endl;
}
