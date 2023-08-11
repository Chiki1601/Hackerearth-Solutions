#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, a, b, sum = 0, ct = 0, i;
    cin >> n;
	if(n % 2 == 1)
    {
		cout << 0;
		return 0;
	}
	vector<vector<long long>> mat(n + 1);
    for(i = 1; i <= n; i++)
        mat[i] = vector<long long> (1, 0);
	for(i = 0; i < n - 1; i++)
    {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	bool visited[n + 1];
	for(i = 1; i <= n; i++)
		visited[i] = 0;
	long long q[n + n], f = 1, r = 1, u, paths[n + 1];
    q[r] = 1;
	visited[1] = 1;
	paths[1] = 0;
	sum = 0;
	while(f <= r && ct < n)
    {
		u = q[f];
		f++;
		for(i = 1; i < mat[u].size(); i++)
        {
			if(visited[mat[u][i]] == 0)
            {
            	paths[mat[u][i]] = (u + mat[u][i]) ^ paths[u];
				sum ^= paths[mat[u][i]];
				visited[mat[u][i]] = 1;
				ct++;
				r++;
				q[r] = mat[u][i];
			}
		}
	}
    cout << sum;
	return 0;
}
