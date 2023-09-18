#include<bits/stdc++.h>
using namespace std;
int dp[200001][2], n;
vector<vector<int>> tree;

int checker(int src, int par, int has)
{
    if(dp[src][has] != -1)
        return dp[src][has];
    int ans = 0;
    for(auto &edge : tree[src])
    {
        if(edge != par)
        {
            int res;
            if(has)
                res = min(1 + checker(edge, src, 1), checker(edge, src, 0));
            else
                res = 1 + checker(edge, src, 1);
            ans += res;
        }
    }
    return dp[src][has] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    tree.resize(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y; 
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    memset(dp, -1, sizeof dp);
    int ans = min(checker(1, 0, 0), 1 + checker(1, 0, 1));
    cout << ans << endl;
    return 0;
}
