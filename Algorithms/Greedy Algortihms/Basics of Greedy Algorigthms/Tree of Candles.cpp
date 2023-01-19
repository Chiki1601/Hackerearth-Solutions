#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n; 
    cin >> t;
    while(t--)
    { 
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<int>> tree;
        tree.resize(n);
        for(int i = 0; i < n - 1; i++)
        {
            int x, y; 
            cin >> x >> y;
            x--; 
            y--;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        vector<bool> vis(n, false);
        set<pair<int, int>> ok;
        ok.insert({a[0], 0});
        int ans = a[0], remain = n;
        while(!ok.empty())
        {
            auto fr = *ok.rbegin();
            ok.erase(fr);
            vis[fr.second] = true;
            remain--;
            ans = min(ans, a[fr.second] - remain);
            for(auto &x : tree[fr.second])
            {
                if(!vis[x])
                    ok.insert({a[x], x});
            }
        }
        if(ans < 0)
            ans = 0;
        cout << ans << "\n";
    }
    return 0;
}
