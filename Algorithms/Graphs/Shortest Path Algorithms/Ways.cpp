#include <bits/stdc++.h>
using namespace std;
int val[1000], d[1000];
vector<pair<int, int>> adjlist[1000];
 
void dijsktra(int s)
{
	priority_queue<pair<int, int>> q;
    q.push(make_pair(0, s));
    int i;
    d[s] = 0;
    while(!q.empty())
    {
    	int u = q.top().second, dist = -q.top().first;
    	q.pop();
    	if(dist > d[u])
            continue;
    	int s = adjlist[u].size();
    	for(int i = 0; i < s; i++)
    	{
    		int v = adjlist[u][i].first;
    		int d1 = d[v], d2 = d[u] + adjlist[u][i].second;
    		if(d2 < d1)
            {
                d[v] = d2;
                val[v] = 1; 
                q.push(make_pair(-d2, v));
            }
    		else if(d2 == d1) 
                val[v]++;
    	}
    }
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, i, j, N, M;
    cin >> T;
    for(i = 1; i <= T; i++)
    {
    	cin >> N >> M;
    	int A, B, C;
    	for(j = 0; j < N; j++)
        {
            adjlist[j].clear();
            d[j] = INT_MAX;
            val[j] = 1;
        }
    	for(j = 0; j < M; j++)
    	{
    	    cin >> A >> B >> C;
    	    adjlist[A - 1].push_back(make_pair(B - 1, C));
    	    adjlist[B - 1].push_back(make_pair(A - 1, C));
    	}
    	dijsktra(0);
        int ans = 1;
    	for(j = 0; j < N; j++)
            ans = ((long long)ans * val[j]) % 1000000007;
    	cout << ans << endl;
    }
    return 0;
}
