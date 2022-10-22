#include<bits/stdc++.h>
using namespace std;
int par[100001];
 
int find(int a)
{
	if(par[a] < 0)
		return a;
	return par[a] = find(par[a]);
}
 
void merge(int a, int b)
{
	if(par[a] > par[b])
		swap(a, b);
	par[a] += par[b];
	par[b] = a;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i <= n; i++)
		par[i] = -1;
	long long int fact[n + 1] = {1}, ans = 1;
	for(int i = 1; i <= n; i++)
		fact[i] = (i * 1LL * fact[i - 1]) % 1000000007;
	for(int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		a = find(a), b = find(b);
		if(a != b)
			merge(a, b);
	}
	for(int i = 0; i <= n; i++)
	{
		if(par[i] < 0)
			ans = (ans * fact[-par[i]]) % 1000000007;
	}
	cout << ans;
}
