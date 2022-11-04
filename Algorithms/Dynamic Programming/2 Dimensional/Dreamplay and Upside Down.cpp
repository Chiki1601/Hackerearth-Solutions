#include<bits/stdc++.h>
using namespace std; 
string s;
 
long long fun(long long i, long long j)
{
	if(i >= j) 
		return 0;
	return 1 - (s[i] == s[j]) + fun(i + 1, j - 1);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	long long ans = 1000000007;
	for(long long i = 0; i < s.size(); i++)
		ans = min(ans, i + fun(i, s.size() - 1));
	cout << ans;
}
