#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int k, n = s.length();
	cin >> k;
	string a[n];
	for(int i = 0; i < n; i++)
		a[i] = s.substr(i, n - i);
	sort(a, a + n);
	cout << a[k - 1] << endl;	
}
