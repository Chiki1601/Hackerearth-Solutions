#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   	int t;
   	cin >> t;
   	while(t--)
   	{
     	string s;
     	cin >> s;
     	map<pair<int, int>, int>mp;
     	mp[{0, 0}] = 1;
     	int a = 0, b = 0, c = 0, res = 0;
     	for(int i = 0; i < s.size(); i++)
     	{
       		if(s[i] == 'a')
        		a++;
       		else if(s[i] == 'b')
             	b++;
            else if(s[i] == 'c')
             	c++;
            pair<int, int>temp = {a - b, a - c};
       		res += mp[temp];
       		mp[temp]++;
     	}
     	cout << res << endl;
   	}        
}
