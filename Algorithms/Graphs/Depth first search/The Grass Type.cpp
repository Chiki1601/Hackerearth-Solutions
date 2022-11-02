#include <bits/stdc++.h>
using namespace std;
vector<int>g[100011];
long long int A[100011], ans = 0;
map<long long int, long long int>M[100011];
 
int dfs(int v, int p)
{
    int r = v, cnt = 0;
    cnt++;
    M[v][A[v]]++;
    long long int cur = 0;
    for(int i = 0; i < g[v].size(); i++)
	{
        if(g[v][i] != p)
		{
            int x = dfs(g[v][i], v);
            if(M[r].size() < M[x].size()) 
				swap(r, x);
            for(map<long long int, long long int>::iterator it = M[x].begin(); it != M[x].end(); it++)
			{
                if(A[v] % it->first == 0)
				{
                    if(M[r].find(A[v] / it->first) != M[r].end())
                        ans += it->second * M[r][A[v] / it->first];
                }
            }
            for(map<long long int, long long int>::iterator it = M[x].begin(); it != M[x].end(); it++)
                M[r][it->first] += it->second;
        }   
    }
    return r;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, u, v;
    cin >> N;
    set<pair<long long int, long long int>>s;
    for(int i = 0; i < N - 1; i++)
	{
        cin >> u >> v;
        s.insert(make_pair(min(u, v), max(u, v)));
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    dfs(1,0);
    cout << ans;
}
