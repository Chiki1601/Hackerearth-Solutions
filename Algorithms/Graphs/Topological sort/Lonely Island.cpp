#include<bits/stdc++.h>
using namespace std;
long long indeg[300000], outdeg[300000];
vector<long long> adj[300000];
double ways[500000];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, m, r;
    cin >> n >> m >> r;
    assert(n <= 300000 && m <= 500000 && r <= n);
    --r;
	for(long long i = 0; i < m; i++)
    {
        long long u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        indeg[v]++,outdeg[u]++;
    }
	ways[r] = 1;
    queue<long long> q;
    for(long long i = 0; i < n; i++)
        if(indeg[i] == 0)
            q.push(i);
	while(!q.empty())
	{
		long long a = q.front();
        q.pop();
		for(auto i : adj[a])
		{
			ways[i] += ways[a] * 1.0 / outdeg[a];
			indeg[i]--;
			if(indeg[i] == 0) 
                q.push(i);
		}
	}
	double mx = 0;
    int idx = 0;
	for(int i = 0; i < n; i++) 
        if(outdeg[i] == 0 && ways[i] > mx)
            mx = max(mx, ways[i]);
	for(long long i = 0; i < n; i++) 
        if(outdeg[i] == 0 && abs(ways[i] - mx) <= 1e-9) 
            cout << i + 1 << ' ' ;
            cout << endl;
}
