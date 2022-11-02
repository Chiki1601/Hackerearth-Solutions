#include<bits/stdc++.h>
using namespace std;
string ans;
unordered_set<string>mp;
 
void dfs(string &s, int a, int h)
{
  	mp.insert(s);
  	ans = min(ans, s);
  	string temp = s;
  	rotate(temp.rbegin(), temp.rbegin() + a, temp.rend());
  	if(mp.find(temp) == mp.end())
    	dfs(temp, a, h);
  	for(int j = 0; j < s.size(); j++)
	{
    	if((j) % 2)
		{
      		int x = s[j] - '0';
      		x = (x + h) % 10;
      		s[j] = x + '0';
    	}
  	}
  	if(mp.find(s) == mp.end())
    	dfs(s, a, h);
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int t;
  	cin >> t;
  	while(t--)
	{
    	mp.clear();
    	string n;
    	cin >> n;
    	int a, h;
    	cin >> a >> h;
    	h %= n.size();
    	ans = n;
    	dfs(n, h, a);
    	cout << ans << endl;
  	}
}
