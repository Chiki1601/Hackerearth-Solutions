#include <bits/stdc++.h>                              
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1, n;
	cin >> t;
	for(int i = 0; i <= t - 1; i++)
	{
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i <= n - 1; i++) 
			cin >> v[i];
		priority_queue<int>q;
		for(int i = 0; i <= n - 1; i++) 
		{
			if(v[i]) 
				q.push(v[i]);
		}
		bool ok = true;
		if(q.size() == 0) 
			ok = false;
		while(q.size() > 1) 
		{
			auto z = q.top();
			q.pop();
			auto mx1 = q.top();
			q.pop();
			if (!(q.size())) 
			{
				if(z == 1 and mx1 == 1) 
					break;
				if(z % (mx1 + 1)) 
				{
					ok = false;
					break;
				}
				z /= (mx1 + 1);
				if(z) 
					q.push(z);
				q.push(mx1);
				continue;
			}
			auto mx2 = q.top();
			if(z - (mx1 * mx2) <= mx2) 
			{ 
				z -= (mx1 * mx2);
				if(z) 
					q.push(z);
				q.push(mx1);
			}
			else 
			{
				if(z % (1 + mx1)) 
				{
					ok = false;
					break;
				}
				z /= (mx1 + 1);
				if(z) 
					q.push(z);
				q.push(mx1);
			}
		}
		if(q.size()) 
			ok = false;
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}
