#include <bits/stdc++.h>
using namespace std;
 
void dfs(vector<vector<pair<long long, long long>>> & graph, long long index, vector<bool> & visited, vector<long long> & subtree, long long & size, vector<pair<long long, long long>> & allAcceptedEdges)
{
    visited[index] = true;
    size++;
    subtree[index]++;
    for(auto itr : graph[index])
	{
        long long node = itr.first, weight = itr.second;
        if(visited[node] == false)
		{
            dfs(graph, node, visited, subtree, size,allAcceptedEdges);
            allAcceptedEdges.push_back({weight, subtree[node]});
            subtree[index] += subtree[node];
        }
    }
}
 
long long temporaryBinaryTreeHelper(long long n, long long start, vector<vector<pair<long long, long long>>> & graph, vector<bool> & visited, vector<long long> & subtree, long long mod)
{
    long long size = 0, ans = 0;
    vector<pair<long long, long long>> allAcceptedEdges;
    dfs(graph, start, visited, subtree, size, allAcceptedEdges);
    for(auto itr : allAcceptedEdges)
	{
        long long weight = itr.first, currSubtreeValue = itr.second;
        ans += weight * currSubtreeValue * (size - currSubtreeValue);
        ans %= mod;
    }
    return ans;
}
 
long long temporaryBinaryTree(long long n, vector<vector<long long>> edges)
{
    long long ans = 0, mod = 1000000007;
    vector<vector<pair<long long, long long>>> graph(n + 1);
    for(long long i = 0; i < n - 1; i++)
	{
        long long u = edges[i][0], v = edges[i][1], type = edges[i][2], weight = edges[i][3];
        if(type == 1)
		{
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
    }
    vector<bool> visited(n + 1, false);
    vector<long long> subtree(n + 1, 0);
    for(long long i = 1; i <= n; i++)
	{
        if(visited[i] == false)
		{
            ans += temporaryBinaryTreeHelper(n, i, graph, visited, subtree, mod);
            ans %= mod;
        }
    } 
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<vector<long long>> edges(n - 1, vector<long long>(4));
        for(long long i = 0; i < n - 1; i++)
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
        cout << temporaryBinaryTree(n, edges) << "\n";
    }

}
