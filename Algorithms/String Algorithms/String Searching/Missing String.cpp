#include <bits/stdc++.h>
using namespace std;
 
inline int addr(const char* s, int n) 
{
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans = 26 * ans + s[i] - 'a' + 1;
	return ans;
}
 
string str(int n) 
{
	string ans;
	while(n > 0) 
	{
		ans.push_back((n - 1) % 26 + 'a');
		n = (n - 1) / 26;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	bitset<475255> L;
	char s[100001];
	cin >> s;
	int n = strlen(s), k = 1;
	for(int k = 0; k < n; ++k) 
	{
		L[addr(s + k, 1)] = 1;
		if(k < n - 1) 
			L[addr(s + k, 2)] = 1;
		if(k < n - 2) 
			L[addr(s + k, 3)] = 1;
		if(k < n - 3) 
			L[addr(s + k, 4)] = 1;
	}
	while(k <= 475254 && L[k]) 
		++k;
	cout << str(k) << endl;
	return 0;
}
