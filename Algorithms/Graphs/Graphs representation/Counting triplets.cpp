#include <bits/stdc++.h>
using namespace std;
long long int deg[100001];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, m;
	cin >> n >> m;
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
 	long long int k = (n * (n - 1) * (n - 2)) / 6, ans = 0;
	for(int i = 1; i <= n; i++)
		ans += deg[i] * (n - 1 - deg[i]);
	cout << k - (ans / 2);
}
