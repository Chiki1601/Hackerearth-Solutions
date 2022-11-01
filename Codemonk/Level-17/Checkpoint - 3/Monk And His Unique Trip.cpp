#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> lowlink, pre, cp, onStack, visited, dp;
stack<int> st;
int timer = 0, componentno = 0, ans = 0;

int sccdfs(int node, vector<vector<int>> &sccgraph, vector<int> &sccvisited)
{
    if(sccvisited[node])
        return dp[node];
    int ans = 0;
    sccvisited[node] = true;
    for(auto child : sccgraph[node])
        ans = max(ans, 1 + sccdfs(child, sccgraph, sccvisited));
    dp[node] = ans;
    return ans;
}

void dfs(int node)
{
    st.push(node);
    pre[node] = lowlink[node] = ++timer;
    onStack[node] = visited[node] = true;
    for(auto child : graph[node])
    {
        if(!visited[child])
        {
            dfs(child);
            lowlink[node] = min(lowlink[child], lowlink[node]);
        }
        else if(onStack[child])
            lowlink[node] = min(lowlink[child], lowlink[node]);
    }
    if(lowlink[node] == pre[node])
    {
        while(true)
        {
            int x = st.top();
            cp[x] = componentno;
            st.pop();
            onStack[x] = false;
            if(x == node)
                break;
        }
        componentno++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, x, y, ans = 0;
    cin >> N >> M;
    graph.resize(N);
    pre.resize(N);
    lowlink.resize(N);
    visited.resize(N);
    onStack.resize(N, false);
    cp.resize(N, -1);
    vector<pair<int, int>> edges;
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        edges.push_back({x, y});
    }
    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
            dfs(i);
    }
    vector<vector<int>> sccgraph(componentno);
    for(int i = 0; i < edges.size(); i++)
    {
        int x = edges[i].first, y = edges[i].second;
        if(cp[x] != cp[y])
            sccgraph[cp[x]].push_back(cp[y]);
    }
    vector<int> sccvisited(componentno, false);
    dp.resize(componentno);
    for(int i = 0; i < componentno; i++)
    {
        if(!sccvisited[i])
            ans = max(ans, sccdfs(i, sccgraph, sccvisited));
    }
    cout << ans << endl;
    return 0;
}
