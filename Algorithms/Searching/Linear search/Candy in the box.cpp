#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t = 1, n, k;
    cin >> t;
    for(int it = 1; it <= t; it++)
    {
		cin >> n >> k;
		long long c = (k - 1) / (n - 1);
		if(c & 1)
			cout << n - (k - 1) % (n - 1) << "\n";
		else
			cout << 1 + (k - 1) % (n - 1) << "\n";
	}
    return 0;
}
