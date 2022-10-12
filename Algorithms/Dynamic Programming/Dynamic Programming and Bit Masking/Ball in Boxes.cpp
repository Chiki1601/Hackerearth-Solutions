#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, c[10000], save[10000], t = 0;
    long long int dp[1024];
	cin >> n;
	string s;
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		cin >> s;
		save[i] = stoi(s, 0, 2);
	}
	for(int i = 0; i < 1024; i++)
	    dp[i] = INT_MAX;
	dp[0] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 1024; j++)
			dp[j|save[i]] = min(dp[j|save[i]], dp[j] + c[i]);
		t |= save[i];
	}	
	cout << dp[t] << endl;
	return 0;
}
