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
	par[a] = b;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		par[i] = -1;
	while(q--)
	{
		int code;
		cin >> code;
		if(code == 1)
		{
			int a, b;
			cin >> a >> b;
			a = find(a), b = find(b);
			if(a != b)
				merge(a, b);
		}
		else if(code == 2)
		{
			int a;
			cin >> a;
			int k = find(a);
			par[k] = a;
			par[a] = -1;
		}	
		else
		{
			int a;
			cin >> a;
			cout << find(a) << endl;
		}
	}
}
