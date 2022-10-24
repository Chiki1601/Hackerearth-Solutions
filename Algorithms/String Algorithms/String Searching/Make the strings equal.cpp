#include<bits/stdc++.h>
using namespace std;
 
bool solve()
{
	int n, cnt[26];
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	memset(cnt, 0, sizeof(cnt));
 	for(int i = 0; i < n; i++)
	{
		cnt[s1[i] - 'a'] += 1;
		cnt[s2[i] - 'a'] -= 1;
	}
	for(int i = 0; i < 26; i++) 
		if(cnt[i] != 0) 
			return false;
	memset(cnt, 0, sizeof(cnt));
 	for(int i = 0; i < n; i++) 
	 	cnt[s1[i] - 'a'] += 1;
	for(int i = 0; i < 26; i++) 
		if(cnt[i] > 1) 
			return true;
 	for(int i = 0; i < 26; i++) 
	 	cnt[i] = INT_MAX;
	int val = 1;
	for(int i = 0; i < n; i++)
	{
		cnt[s1[i] - 'a'] = val;
		val++;
	}
 	int inv = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(cnt[s2[j] - 'a'] < cnt[s2[i] - 'a']) 
				inv++;
		}
	}
	return (inv % 2 == 0);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	{
		if(solve()) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}
