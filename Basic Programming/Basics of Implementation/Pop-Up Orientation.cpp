#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t, x, y, l, m, a, b;
	cin >> t;
	while(t--)
	{
		cin >> x >> y >> l >> m >> a >> b;
		if((a + l <= x) && (b - m >= 0))
			cout << "bottom-right" << endl;
		else if((a - l >= 0) && (b - m >= 0))
			cout << "bottom-left" << endl;
		else if((a + l <= x) && (b + m <= y))
			cout << "top-right" << endl;
		else if((a - l >= 0 && (b + m <= y)))
			cout << "top-left" << endl;
	}
	return 0;
}
