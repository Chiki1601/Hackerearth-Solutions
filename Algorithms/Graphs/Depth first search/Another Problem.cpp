#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> a, lastOfString, pref;
vector<bool> vis;
map<string, vector<int>> mid;
vector<vector<int>> ok;
vector<int> order;

void dfs(string &curLast)
{
    if(order.size() == n)
    {
        ok.push_back(order);
        return;
    }
    for(auto &x : mid[curLast])
    {
        if(!vis[x])
        {
            vis[x] = true;
            order.push_back(x);
            dfs(lastOfString[x]);
            order.pop_back();
            vis[x] = false;
        }
    }
}
    
int main()
{
    cin >> n;
    a.resize(n);
    vis.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        string me = "";
        for(int j = 0; j < 4; j++)
            me += a[i][j];
        string me2 = "";
        for(int j = 3; j >= 0; j--)
            me2 += a[i][a[i].length() - 1 - j];
        lastOfString.push_back(me2);
        mid[me].push_back(i);
        string me3 = "";
        for(int j = 4; j < a[i].length(); j++)
            me3 += a[i][j];
        pref.push_back(me3);
        vis[i] = false;
    }
    map<string, bool> dp;
    for(int i = 0; i < n; i++)
    {
        if(dp[a[i]])
            continue;
        vis[i] = true;
        order.push_back(i);
        dfs(lastOfString[i]);
        order.pop_back();
        dp[a[i]] = true;
        vis[i] = false;
    }
    set<string> ans;
    for(auto &r : ok)
    {
        string cur = a[r[0]];
        for(int i = 1; i < r.size(); i++)
            cur += pref[r[i]];    
        ans.insert(cur);
    }
    for(auto &x : ans)
        cout << x << endl;
    return 0;
}
