#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q, k;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for(int i = 0; i < n; i++) 
		cin >> v[i];
	sort(v.begin(), v.end());
	cin >> q;
	while(q--) 
	{ 
		char c;
		cin >> k >> c;
		if(c == 'S')
			cout << v[k - 1] << "\n";
		else
			cout << v[n - k] << "\n";
	}
	return 0;
}
