#include<bits/stdc++.h>
using namespace std;
int ans;
 
void dfs(int i, int j, vector<vector<char>> &v)
{
    int r = v.size(), c = v[0].size();
    if(i < 0 or j < 0) 
		return;
    if(i >= r or j >= c) 
		return;
    if(v[i][j] not_eq '.') 
		return;
    v[i][j] = '#';
    ans++;
    dfs(i - 1, j, v);
    dfs(i + 1, j, v);
    dfs(i, j - 1, v);
    dfs(i, j + 1, v);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
	cin >> t;
    while(t--)
	{
        int r, c; 
		cin >> r >> c;
        vector<vector<char>> adj(r, vector<char> (c, 0));
        for(int i = 0; i < r; i++)
		{
            for(int j = 0; j < c; j++)
                cin >> adj[i][j];
        }
        vector<int>v;
        for(int i = 0; i < r; i++)
		{
            for(int j = 0; j < c; j++)
			{
                if(adj[i][j] == '.')
				{
                    dfs(i, j, adj);
                    v.push_back(ans);
                    ans = 0;
                }
            }
        }
        cout << v.size() << endl;
        for(auto &it:v) 
			cout << it << " ";
        cout << endl;
    }
}
