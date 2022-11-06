#include <bits/stdc++.h>
using namespace std;
 
void read() 
{
	int n;
    cin >> n;
	long long ans = 0;
	bool g0 = false;
	for (int i = 0; i < n; ++i) 
    {
		long long len, d;
		cin >> len >> d;
		if(d > 0) 
            g0 = true;
		ans += (len * d) % 9;
		if(ans >= 9) 
            ans -= 9;
	}
	if(ans == 0 and g0) 
        ans = 9;
	cout << ans << endl;
}
 
int main() 
{
    int t, TEST_NO;
	cin >> t;
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) 
		read();
	return 0;
}
