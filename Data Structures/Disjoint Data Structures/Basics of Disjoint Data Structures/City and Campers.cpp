#include <bits/stdc++.h>
using namespace std;
set <pair<int,int>> keep;
int parent [100005], sz[100005];
 
int findset (int a)
{
	if(parent[a] == 0)
		return a;
	return parent[a] = findset(parent[a]);
}
 
void merge (int a, int b)
{
	int k = findset(a), kk = findset(b); 
	if(k == kk)
		return;
	parent[k] = kk; 
	keep.erase(pair<int,int>(sz[kk], kk));
	keep.erase(pair<int,int>(sz[k], k));
	sz[kk] += sz[k];
	keep.insert(pair<int,int>(sz[kk],kk));
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N, Q; 
	cin >> N >> Q;
	for(int g = 1; g <= N; g++)
		keep.insert(pair<int,int>(1, g)),sz[g] = 1;
	for(int g = 0; g < Q; g++)
	{
		int a, b; 
		cin >> a >> b;
		merge(a, b); 
		set <pair<int,int>> :: iterator ending = keep.end(); ending--; 
		set <pair<int,int>> :: iterator beginning = keep.begin(); 
		cout << (*ending).first - (*beginning).first << endl; 
	}	
	return 0; 
}
