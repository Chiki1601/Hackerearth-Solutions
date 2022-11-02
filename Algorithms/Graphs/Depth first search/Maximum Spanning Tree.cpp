#include<bits/stdc++.h>
using namespace std;
int par[5001];
 
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
	int t;
	cin >> t;
	while(t--)
	{
 		int n, m;
 		cin >> n >> m;
 		pair<int, pair<int, int> >p[m];
 		for(int i = 0; i < m; i++)
 		{
  			int a, b, c;
  			cin >> a >> b >> c;
  			p[i] = make_pair(-c, make_pair(a, b));
 		}
 		sort(p, p + m);
 		long long int sum = 0;
 		for(int i = 1; i <= n; i++)
 			par[i] = -1;
 		for(int i = 0; i < m; i++)
 		{
  			pair<int, pair<int, int>>pr = p[i];
  			int a = pr.second.first, b = pr.second.second;
  			a = find(a), b = find(b);
  			if(a != b)
  			{
   				merge(a, b);
   				sum -= 1LL * pr.first;
  			}
 		}
 		cout << abs(sum) << endl;
	}
}
