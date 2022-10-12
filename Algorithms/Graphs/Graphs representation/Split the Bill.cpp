#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, j = 0;
    cin >> n >> m;
    vector<long long int>balance(n, 0ll); 
    for(int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        int np, ns;
        cin >> np >> ns;
        for(int j = 0; j < np; ++j)
        {
            int id;
            long long int amt;
            cin >> id >> amt;
            balance[id - 1] -= amt; 
        }
        for(int j = 0; j < ns; ++j)
        {
            int id;
            long long int amt;
            cin >> id >> amt;
            balance[id - 1] += amt;
        }
    }
    vector<pair<pair<int, int>, long long int>> ans;
    for(int i = 0; i < n; ++i)
    {
        if(balance[i] > 0)
        {
            long long int curr = balance[i];
            while(curr > 0 && j < n)
            {
                if(balance[j] >= 0)
                {
                    j++;
                    continue;
                }
                long long int mini = min(curr, abs(balance[j]));
                curr -= mini;
                balance[j] += mini;
                ans.push_back({{i + 1, j + 1}, mini});
            }
        }
    }
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
    return 0;
}
