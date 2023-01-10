#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for(int c = 1; c <= tc; c++) 
    {
		int n, s1 = 0, s2 = 0;
		cin >> n;
		vector<int> arr(n), barr(n);
		for(auto &x : arr)
			cin >> x;
		for(auto &x : barr)
			cin >> x;
		for(int i = 0; i< n; i++) 
		{
			s1 += (i + 1) * arr[i];
			s2 += (i + 1) * barr[i];
		}
		s1 == s2 ? cout << "Yes\n" : cout << "No\n";
	}
    return 0;
}
