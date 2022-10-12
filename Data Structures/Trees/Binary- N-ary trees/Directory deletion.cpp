#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
bool to_delete[100001];
int p[100001], ans = 0;
 
void dfs(int node) 
{
    if(to_delete[node] == 1) 
    {
        ++ans;
        return;
    }
    for(int i: graph[node]) 
        dfs(i);
}
 
int main()  
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    assert(cin >> n);
    assert(n >= 1 && n <= 100000);
    for(int i = 1; i <= n; i++) 
    {
        assert(cin >> p[i]);
        assert(p[i] <= n);
        if(p[i] != -1)
            graph[p[i]].push_back(i);
    }
    int k;
    assert(cin >> k);
    for(int i = 1; i <= k; i++) 
    {
        int val;
        assert(cin >> val);
        assert(val <= n && val >= 1);
        to_delete[val] = 1;
    }
    dfs(1);
    cout << ans;
}
