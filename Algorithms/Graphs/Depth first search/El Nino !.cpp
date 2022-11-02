#include <bits/stdc++.h> 
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n, m;
  	cin >> n >> m;
    vector<int> a(m), dist(n + 1);
  	for(int i = 0; i < m; i++) 
    	cin >> a[i];
  	sort(begin(a), end(a));
    vector<vector<int>> t(n+1);
  	for(int i = 2; i <= n; i++) 
	{
    	int p; 
		cin >> p;
    	t[p].push_back(i);
  	}
    queue<int> q;
    q.push(1);
    long long tot = 0;
  	while(!q.empty()) 
	{
    	int u = q.front(); 
		q.pop();
    	int d = dist[u];
    	tot += upper_bound(begin(a), end(a), d) - begin(a);
    	for(int v : t[u]) 
		{
      		q.push(v);
      		dist[v] = dist[u] + 1;
    	}
  	}
    cout << tot << endl;
    return 0;
}
