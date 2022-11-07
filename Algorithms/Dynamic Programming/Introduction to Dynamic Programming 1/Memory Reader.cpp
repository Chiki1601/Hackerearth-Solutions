#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int T, n;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) 
			cin >> a[i];
		unordered_map<int, int> s[n];
		s[0][a[0]] = 1;
		for(int i = 1; i < n; i++) 
		{
			for(int j = 0; j < i; j++) 
			{
				int val = a[i] - a[j];
				if(s[j][val] or s[j][val - 1] or s[j][val + 1]) 
					s[i][val] = 1;
			}
		}
		if(s[n - 1].size() > 0) 
			cout << "YES\n";
		else 
			cout << "NO\n"; 
	}  
	return 0;  
}
