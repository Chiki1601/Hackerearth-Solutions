#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, p[300000], donde[300000], n;
	cin >> t;
    while(t--) 
	{
		cin >> n;
		for(int i = 0; i < n; ++i) 
			cin >> p[i];
		for(int i = 0; i < n; ++i) 
			donde[p[i]] = i;
		int mn = donde[0];
		int mx = mn;
		for(int i = 1; i < n; ++i)
		{
			if(donde[i] > mn && donde[i] < mx) 
				cout << 0 << " ";
			else if (donde[i] > mx)
				cout << (long long)(mn + 1) * (donde[i] - mx) << " ";
			else
				cout << (long long)(mn - donde[i]) * (n - mx) << " ";
			mn = min(mn, donde[i]);
			mx = max(mx, donde[i]);
		}
		cout << 1 << "\n";
	}
    return 0;
}
