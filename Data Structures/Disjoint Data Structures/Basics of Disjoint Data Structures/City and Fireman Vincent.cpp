#include<bits/stdc++.h>
using namespace std;
int parent[1005], risks[1005];
 
void make(int i) 
{
	parent[i] = i;
}
 
int find_par(int v) 
{
	if(v == parent[v])
		return v;
	return parent[v] = find_par(parent[v]);
}
 
void Union(int a, int b) 
{
	a = find_par(a);
	b = find_par(b);
	if(a != b) 
	{
		if(risks[a] > risks[b])
			swap(a, b);
		parent[b] = a;
	}
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> risks[i];
		make(i);
	}	
	cin >> k;
	while(k--) 
	{
		int i, j;
		cin >> i >> j;
		Union(i, j);
	}
	long long ans = 1;
	unordered_map<int, int>mp;
	for(int i = 1; i <= n; i++) 
	{
		if(risks[find_par(i)] == risks[i]) 
			mp[find_par(i)]++;
	}
	for(auto it : mp)
		ans= (ans * it.second) % 1000000007;
	cout << ans << endl;
}
