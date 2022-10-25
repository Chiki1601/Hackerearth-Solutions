#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<int, int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
vector<int> graph[2000001];
bool visit[2000001];
int idx = 0, a[2000001], b[2000001];
long long int final_ans = 0;
unordered_map<int,int> m;
ordered_set BIT[200001];
 
void remove(int pos, int val, int node)
{
    while(pos <= 200000)
    {
        BIT[pos].erase(make_pair(val , node));
        pos += (pos & (-pos));
    }   
}
 
void add(int pos, int val, int node)
{
    while(pos <= 200000)
    {
        BIT[pos].insert(make_pair(val, node));
        pos += (pos & (-pos));
    }
}
 
void query(int pos, int val)
{
    while(pos > 0)
    {
        final_ans = final_ans + (long long int )(BIT[pos].order_of_key(make_pair(val, 0)));
        pos -= (pos & (-pos));
    }
}
 
void dfs(int node)
{
    ++idx;
    query(m[a[node]]-1, m[b[node]]);   
    add(m[a[node]], m[b[node]], node);
    visit[node] = 1;
    for(int i = 0; i < graph[node].size(); i++)   
    {
        if(visit[graph[node][i]] == 0)
        {   
            visit[graph[node][i]] = 1;
            dfs(graph[node][i]);
        }
    }
    remove(m[a[node]], m[b[node]], node);
    --idx;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    set<int> temp;
    for(int i = 1; i <= n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        temp.insert(a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        temp.insert(b[i]);
    }
    int idxs = 0;
    for(int i : temp)
        m[i] = ++idxs;
    temp.clear();
    dfs(1);
    cout << final_ans;
}
