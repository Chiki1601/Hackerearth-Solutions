#include <bits/stdc++.h>
using namespace std;
vector<int> a[100];
int siz = 0, vis[100];
 
void dfs(int r)
{
	siz++;
	vis[r] = 1;
	for(int child : a[r])
	    if(!vis[child])
	        dfs(child);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
    cin >> t;
    long long int dp[201];
	dp[1] = 0, dp[2] = 1;
	for(long long int i = 3; i <= 200; i++)
	    dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
	while(t--)
	{
		int n, m, x, y;
        cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
            vis[i] = 0;
            a[i].clear();
        }
		while(m--)
		{
			cin >> x >> y;
			a[x].push_back(y);
            a[y].push_back(x);
		}
		vector<int> v;
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
			{
				siz = 0;
				dfs(i);
				v.push_back(siz);
			}
		}
		cout << v.size() << endl;
		sort(v.rbegin(), v.rend());
		for(int i = 0; i < v.size(); i++)
		    cout << dp[v[i]] << ' ';
		cout << endl;
	}
}
