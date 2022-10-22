#include<bits/stdc++.h>
using namespace std;
int par[1000005];
 
int find(int x)
{
	if(par[x] == -1)
		return x;
	else 
		return find(par[x]);
}
 
void merge(int x, int y)
{
    par[x] = y;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= 100005; i++)
		par[i] = -1;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		if(find(x) != find(y))
			merge(x, y);
	}
	vector<int>v;
	for(int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if(c == 'E')
		{
			int x;
			cin >> x;
			if(par[x] == -1)
				v.push_back(x);
			else
			{
				auto it = find(v.begin(), v.end(), par[x]);
				if(it == v.end())
				{
					v.push_back(x);
					par[par[x]] = x;
				}
				else
				{
					v.insert(++it, x);
					par[par[x]] = x;
				}
			}
		}
		else
		{
			auto it = v.begin();
			cout << (*it) << endl;
			v.erase(it);
		}
	}
}
