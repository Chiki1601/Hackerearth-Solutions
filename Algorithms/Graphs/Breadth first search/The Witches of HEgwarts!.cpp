#include<bits/stdc++.h>
using namespace std;
unordered_map<long long, long long>m;
 
long long solve(long long n)
{
	if(n == 0)
	    return INT_MAX;
	if(n == 1)
	    return 0;
	if(n <= 3)
	    return 1;
	if(m.find(n) != m.end())
	    return m[n];
	long long res = min(n % 2 + solve(n / 2) , n % 3 + solve(n / 3)) + 1;
	return m[n] = res;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
