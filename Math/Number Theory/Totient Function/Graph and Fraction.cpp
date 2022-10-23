#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	long long t;
  	cin >> t;
  	while(t--)
  	{
  		long long n, m, a, b; 
  		cin >> n >> m;
  		long long M = m, phi[n + 5], ans[n + 5];
  		vector<long long> adj[n + 5];
  		while(M--)
  		{
  			cin >> a >> b;
  			adj[a].push_back(b);
  			adj[b].push_back(a);
  		}
    	for(long long i = 1; i <= n; i++) 
        	phi[i] = i; 
    	for(long long p = 2; p <= n; p++) 
    	{ 
        	if(phi[p] == p) 
        	{ 
            	phi[p] = p - 1;
            	for(long long i = 2 * p; i <= n; i += p) 	 
               		phi[i] = (phi[i] / p) * (p - 1);  
        	} 
    	}	 
    	for(long long i = 1; i <= n; i++)
    	{
    		if(i % 2 == 1)
    		{
    			ans[i] = (n / i) * phi[i];
    			ans[i] /= 2;
    		}
    		else
    			ans[i] = 0;
    	}
  		for(long long i = 1; i <= n; i += 2)
  		{
  			for(long long j = 0; j < adj[i].size(); j++)
  			{
  				long long v = adj[i][j];
  				if(v % 2 == 1 and v <= i and __gcd(v, i) == 1)
  					ans[i] -= (n / i);
  			}
  		}
  		ans[1] = 0;
  		for(long long i = 1; i <= n; i++)
  			cout << ans[i] << " ";
    	cout << endl;
  	}
}
