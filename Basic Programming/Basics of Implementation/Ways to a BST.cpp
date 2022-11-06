#include<bits/stdc++.h>
using namespace std;
int n,a[1007];
int NCR[1007][1007];
bool visited[1007][1007];
 
int ncr(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    if(n < r)
        return 0;
    if(visited[n][r])
        return NCR[n][r];
    visited[n][r] = true;
    NCR[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
    NCR[n][r]=NCR[n][r] % 1000000007;
    return NCR[n][r];
}
 
int func(vector<int>&nodes)
{
    if(nodes.size() <= 1)
        return 1;
    int root = nodes[0];
    vector<int>leftSubtree,rightSubtree;
    for(auto j:nodes)
        if(j < root)
            leftSubtree.push_back(j);
        else if(j > root)
            rightSubtree.push_back(j);
    long long ans = 1;
    ans = ans * func(leftSubtree) * func(rightSubtree);
    ans %= 1000000007;
    ans *= ncr(nodes.size() - 1, leftSubtree.size());
    ans %= 1000000007;
    return ans;
}
 
int func()
{
    vector<int>nodes(a + 1, a + n + 1);
    return func(nodes);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        cout << func() << endl;
    }
    return 0;
}
