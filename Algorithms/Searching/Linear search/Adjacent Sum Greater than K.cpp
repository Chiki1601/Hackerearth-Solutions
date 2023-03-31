#include<bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) 
	{
		int n, k, last = 1;
		cin >> n >> k;
		if(k > n + 1) 
		{
			cout << "-1" << endl;
			continue;
		}
		cout << "1 ";
		set<int> st;
		for(int i = 2; i <= n; i++) 
			st.insert(i);
		for(int i = 0; i < n - 1; i++) 
		{
			int cur = *st.lower_bound(k - last);
			st.erase(cur);
			cout << cur << ' ';
			last = cur;
		}
		cout << endl;
	}
	return 0;
}
