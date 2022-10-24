#include<bits/stdc++.h>
using namespace std;
vector<int>p,q;
 
void dfs(vector<int>list[], int *a, int *b, int sv, bool *vis)
{
	vis[sv] = 1;
	p.push_back(a[sv]);
	q.push_back(b[sv]);
	for(int i = 0; i < list[sv].size(); i++)
	{
		if(!vis[list[sv][i]])
			dfs(list, a, b, list[sv][i], vis);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[n];
		for(int i = 0; i < n; cin >> a[i++]);
			for(int j = 0; j < n; cin >> b[j++]);
				vector<int>list[n + 1];
				for(int i = 0; i < m; i++)
				{
					int u, v;
					cin >> u >> v;
					list[u-1].push_back(v - 1);
					list[v-1].push_back(u - 1);
				}	
				bool *vis = new bool[n](), ans = 1;
				for(int i = 0; i < n; i++)
				{
					if(!vis[i])
					{
						p.clear();
						q.clear();
						dfs(list, a, b, i, vis);
						sort(p.begin(), p.end());
						sort(q.begin(), q.end());
						if(p != q)
							ans = 0;
					}
				}
				ans == 1 ? cout << "YES" << endl : cout << "NO" << endl;
	}
}
