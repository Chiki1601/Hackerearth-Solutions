#include<bits/stdc++.h>
using namespace std;
int p[200001];
 
int root(int a)
{
  	while(a != p[a])
  	{
    	p[a] = p[p[a]];
    	a = p[a];
  	}
  	return a;
}
 
bool uni(int a, int b)
{
  	a = root(a);
  	b = root(b);
  	if(a == b)
    	return true;
  	p[b] = a;
  	return false;
}
 
int main()
{
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int t;
  	cin >> t;
  	while(t--)
  	{
    	int n, z = 0, ans = 0;
    	cin >> n;
    	iota(p, p + 2 * n, 0);
    	unordered_map<string, int>mp;
    	for(int h = 0; h < n; h++)
		{
      		string a, b;
      		cin >> a >> b;
      		if(mp.count(a) == 0)
        		mp[a] = z++;
      		if(mp.count(b) == 0)
        		mp[b] = z++;
      		if(a == b)
        		continue;
      		ans++;
      		if(uni(mp[a], mp[b]))
        		ans++;
    	}
    	cout << ans << endl;
  	}
}
