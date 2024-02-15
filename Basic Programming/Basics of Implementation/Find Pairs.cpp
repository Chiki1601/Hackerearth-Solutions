#include <bits/stdc++.h>
using namespace std;
 
long long check(const vector<long long> &a, long long x) 
{
	const int n = a.size();
	long long r = 0;
	int odd = 0;
	for(long long v : a) 
		odd += v & 1;
	for(int i = 0, j = n - 1; i < j; ++i) 
    {
		odd -= a[i] & 1;
		for(; i < j && a[i] + a[j] > x; odd -= a[j--] & 1);
		r += a[i] & 1 ? (j - i - odd) : odd;
	}
	return r;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	long long x, y;
	cin >> n >> x >> y;
	vector<long long> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	sort(a.begin(), a.end());
	cout << check(a, y) - check(a, x - 1) << endl;
	return 0;
}
