#include<bits/stdc++.h>
using namespace std;
vector<int>a[1000001], c[1000001];
int v[1000001] = {0}, b[1000001] = {0}, d[1000001] = {0};
 
void dfs(int s, int k)
{
    v[s] = 1;
    if(c[b[s]].size() >= k)
    {
        int size = c[b[s]].size();
        d[s] = c[b[s]][size - k];
    }
    else
    d[s] = -1;
	c[b[s]].push_back(s);
    for(int i = 0; i < a[s].size(); i++)
    {
        if(v[a[s][i]] == 0)
            dfs(a[s][i], k);
    }
    if(c[b[s]].size() != 0)
    	c[b[s]].pop_back();
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, i;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
    	cin >> b[i];
    for(i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, k);
    for(i = 1; i <= n; i++)
    	cout << d[i] << " ";
}
