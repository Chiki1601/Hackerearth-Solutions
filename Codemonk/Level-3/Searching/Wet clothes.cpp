#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, m, g;
	cin >> n >> m >> g;
	int t[n], a[m], mm = 0, count = 0;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < m; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++)
		mm = max(mm, t[i] - t[i - 1]);
	sort(a, a + m);
	for(int i = 0; i < m; i++)
	{
		if(a[i] <= mm)
			count++;
	}
	cout << count << endl;	
}
