#include<bits/stdc++.h>
using namespace std;
vector<long long> hsh[1001000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, left = 0, right = INT_MAX, ans = 0, pw[1001000];
  	pw[0] = 1;
  	for(int i = 1; i <= 1000000; i++)
    	pw[i] = pw[i - 1] * 31;
	cin >> n;
  	for(long long i = 1; i <= n; i++)
	{
    	string str = "";
    	cin >> str;
    	right = min(right, (long long)str.length());
    	hsh[i].push_back(0);
    	for(long long j = 0; j < str.length(); j++)
      		hsh[i].push_back(hsh[i].back() * 31 + (str[j] - 'a' + 1));
  	}
  	while(left <= right)
	{
    	long long mid = (left + right) / 2, cur = 0, prev = 1;
    	set<long long> s[2];
    	for(int i = 1; i <= n; i++)
		{
      		for(int j = mid; j < hsh[i].size(); j++)
			{
        		int k = j - mid;
        		long long h = hsh[i][j] - (pw[mid] * hsh[i][k]);
        		if(i == 1)
					s[cur].insert(h);
        		else
				{
          			if(s[prev].find(h) != s[prev].end())
            			s[cur].insert(h);
        		}
      		} 
      		s[prev].clear();
      		cur = 1 - cur;
      		prev = 1 - prev;
    	}
    	if(s[prev].size())
		{
      		left = mid + 1;
      		ans = mid;
    	}
    	else 
			right = mid - 1;
  	}
  	cout << ans << "\n";
  	return 0;
}
