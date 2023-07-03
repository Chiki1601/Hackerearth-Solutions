#include <bits/stdc++.h>
using namespace std; 

template<class T> bool ckmin(T&a, const T& b) 
{ 
	bool B = a > b; 
	a = min(a, b); 
	return B; 
}

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
    {
		int n, x; 
		cin >> n >> x;
		string s, t; 
		cin >> s >> t;
		vector<int> A;
		for(int i = 0; i < n; ++i) 
		{
			if(s[i] != t[i]) 
				A.push_back(i);
		}
		n = (int)(A).size();
		if(n % 2) 
		{
			cout << -1 << "\n";
			continue;
		}
		vector<long long> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for(int i = 2; i <= n; i += 2) 
		{
			dp[i] = A[i - 1] - A[i - 2] + dp[i - 2];
			int cost = 0;
			for(int k = i - 1; k >= 1; k -= 2) 
			{
				ckmin(dp[i], dp[k - 1] + x + cost);
				if(k - 2 >= 0) 
					cost += A[k - 1] - A[k - 2];
			}
		}
		cout << (dp[n] >= INT_MAX ? -1 : dp[n]) << "\n";
	}
    return 0;
}
