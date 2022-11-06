#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
 	cin >> n;
 	int A[n], B[n];
 	for (int i = 0; i < n; ++i)
 		cin >> A[i];
 	for (int i = 0; i < n; ++i)
 		cin >> B[i];
 	map <int, int> val;
 	for (int i = 0; i < n; ++i)
 		val[A[i]] = max(B[i], val[A[i]]);
 	for (int i = 0; i < n; ++i)
 		cout << val[A[i]] << " ";
 	return 0;
}
