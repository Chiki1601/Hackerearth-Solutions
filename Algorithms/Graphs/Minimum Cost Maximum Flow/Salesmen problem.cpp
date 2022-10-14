#include<bits/stdc++.h>
using namespace std;      
long long a[510][510];
 
long long hungary(int n, int m) 
{
  	vector<long long> u(n + 1), v(m + 1);
  	vector<int> p(m + 1), way(m + 1);
  	for(int i = 1; i <= n; ++i) 
  	{
    	p[0] = i;
    	int j0 = 0;
    	vector<long long> minv (m + 1, 1000000000000);
    	vector<char> used (m + 1, 0);
    	do 
		{
      		used[j0] = 1;
      		int i0 = p[j0], j1 = 0;
      		long long d = 1000000000000;
      		for(int j = 1; j <= m; ++j)
        		if(!used[j]) 
				{
          			long long cur = a[i0][j] - u[i0] - v[j];
          			if(cur < minv[j])
					{
            			minv[j] = cur; 
						way[j] = j0;
					}
          			if(minv[j] < d)
            		{	
						d = minv[j]; 
						j1 = j;
					}
        		}
      		for(int j = 0; j <= m; ++j)
        		if(used[j])
          		{	
					u[p[j]] += d; 
					v[j] -= d;
				}
        		else
          			minv[j] -= d;
      			j0 = j1;
    	} while(p[j0] != 0);
    	do 
		{
      		int j1 = way[j0];
      		p[j0] = p[j1];
      		j0 = j1;
    	} while(j0);
  	}
   	vector<int> ans (n + 1);
  	for(int j = 1; j <= m; ++j)
    	ans[p[j]] = j;
  	long long cost = -v[0];
  	return cost;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	for(int i = 1; i <= t; i++)
	{
		long long n, m;
		cin >> n >> m;
		for(long long i = 1; i <= n; ++i)  
		{
			for(long long j = 1; j <= n; ++j)  
				a[i][j] = 1000000000000;
		}
		for(long long i = 1; i <= n; ++i) 
			cin >> a[i][i];
		for(long long i = 0; i < m; ++i)
		{
			long long x, b, c;
			cin >> x >> b >> c;
			a[x][b] = min(a[x][b], c);
		}
		for(int k = 1; k <= n; k++)
		{
			for(long long i = 1; i <= n; ++i) 
				for(long long j = 1; j <= n; ++j)  
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
		}
		long long ans = hungary(n, n);
		cout << ans << endl;
	}
}
