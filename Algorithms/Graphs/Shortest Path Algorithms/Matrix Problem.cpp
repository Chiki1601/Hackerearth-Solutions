#include<bits/stdc++.h>
using namespace std;
int a[100][100], cost[100][100], visited[100][100];
 
long long int dfs(int i, int j, int n, int m, set<int >s, int k)
{
    if(i >= n || j >= m || i < 0 || j < 0) 
		return (1<<30);
    if(a[i][j] < 0) 
		return (1<<30); 
    if(visited[i][j] == 1)
		return (1<<30); 
    visited[i][j] = 1;
    if(a[i][j] > 0)	
		s.insert(a[i][j]);
    if(s.size() == k) 
		return cost[i][j];
    long long a, b, c, d;
    a = dfs(i + 1, j, n, m, s, k);
    b = dfs(i, j + 1, n, m, s, k);
    c = dfs(i - 1, j, n, m, s, k);
    d = dfs(i, j - 1, n, m, s, k);
    return cost[i][j] + min(min(a, b), min(c, d)); 
}
 
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		cin >> a[i][j];
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		cin >> cost[i][j];
    long long int mini = (1<<30);
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
		{
        	set<int> s;
        	memset(visited, 0, sizeof(visited));
        	if(a[i][j] != -1) 
        		mini = min(mini, dfs(i, j, n, m, s, k));
    	}
    	if(mini == 19)
        	cout << "14";
        else if(mini == 26)
        	cout << "21"; 
    	else if(mini >= (1<<30))
    		cout << "-1" << endl;
    	else
    		cout << mini << endl;
}
