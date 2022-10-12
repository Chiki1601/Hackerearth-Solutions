#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans = 0, a;
	stack<int> stk;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		while(!stk.empty() and a > stk.top())
		{
			stk.pop();
			ans++;
		}
		if(!stk.empty()) 
            ans++;
		stk.push(a);
	}
	cout << ans << endl;
	return 0;
}
